// import { http } from "http";
const http = require('node:http');
const net = require('node:net');
const { URL } = require('node:url');
const { resolve } = require("path");
const { Worker, parentPort, isMainThread } = require("worker_threads");

// import { net } from "net"
// import { URL } from "url";
// import { resolve } from "path";
// import 
// {
// 	/* workerData, */
// 	Worker,
// 	parentPort,
// 	isMainThread
// } from "worker_threads";

if (isMainThread)
{
	let 	a = 0;
	const	arr = new Array;
	while (a++ < 10)
	{
		arr.push(new Promise((resolve, rejects)=>
		{
			const tworker = new Worker("./ddos", {workerData: "test"} );
			tworker.on("message", e=>
			{
				console.log(e);
				resolve(e);
			});
			tworker.on("error", e=>
			{
				console.log(e);
				rejects(e);
			});
			tworker.on("exit", e=>
			{
				console.log(e);
				resolve(e);
			});	
		}))
	}
}
else
{
	// Create an HTTP tunneling proxy
	const proxy = http.createServer((req, res) => {
		res.writeHead(200, { 'Content-Type': 'text/plain' });
		res.end('okay');
	});
	proxy.on('connect', (req, clientSocket, head) => {
	// Connect to an origin server
		const { port, hostname } = new URL(`http://${req.url}`);
		const serverSocket = net.connect(port || 80, hostname, () => {
			clientSocket.write('HTTP/1.1 200 Connection Established\r\n' +
							'Proxy-agent: Node.js-Proxy\r\n' +
							'\r\n');
			serverSocket.write(head);
			serverSocket.pipe(clientSocket);
			clientSocket.pipe(serverSocket);
		});
	});

	// Now that proxy is running
	proxy.listen(8882, '127.0.0.1', () => {

		// Make a request to a tunneling proxy
		const options = {
			port: 8882,
			host: '127.0.0.1',
			method: 'CONNECT',
			path: 'fasttyping.com.tr',
		};


		

		const req = http.request(options);
		req.end();

		req.on('connect', (res, socket, head) => {
			console.log('got connected!');

			// Make a request over an HTTP tunnel
			socket.write('POST / HTTP/1.1\r\n' +
						'Host: fasttyping.com.tr:443\r\n' +
						'Connection: close\r\n' +
						'\r\n');
			socket.on('data', (chunk) => {
				console.log(chunk.toString());
			});
			socket.on('end', () => {
				proxy.close();
			});
		});
		req.on("response", e=>
		{
			console.log(e);
		})






	});










/* 	xhttp = new XMLHttpRequest();
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function()
	{
		if (this.readyState == 4 && this.status == 200)
		{
			// Typical action to be performed when the document is ready:
			parentPort.postMessage(xhttp.responseText);
		}
	};


	xhttp.onload = function()
	{
		parentPort.postMessage(`Loaded: ${xhttp.status} ${xhttp.response}`);
	};

	xhttp.onerror = function()
	{
		parentPort.postMessage("Request failed");
	};
	

	xhttp.open("POST", "posts.php?action=score", true);
	xhttp.send("dataaaaaa");
	parentPort.postMessage("anan(annen)"); */
}
