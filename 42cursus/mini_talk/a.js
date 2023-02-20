let ix = 0;
setInterval(e=>{
    a = document.getElementById("textArea").childNodes[ix].textContent
    console.log(a, ix, document.getElementById("textArea").childNodes[ix])
    document.getElementById("textInput").value = a
    ix++;
    
e = {keyCode: 32}
text = $("input[id='textInput']")[0].value;
postWithFunction("score", function(response) {
                document.getElementById('falseWcounter').innerHTML = response.false_word;
                document.getElementById('trueWcounter').innerHTML = response.true_word;
            }, {
                "input": text.split(String.fromCharCode(e.keyCode))[0].toLowerCase()
            });
}, 100)


async function postWithFunction(action, callback, data=null, type="POST") {
    await $.ajax({
        type: type,
        url: "posts.php?action=" + action,
        data: data,
        async: true,
        success: function(request) {
            callback(request);
        },
        error: function(request, error) {
            if (request.responseText.length > 1)
                callback(request.responseText);
            else {
                alert("Error!");
            }
        }
    });
}

e = {keyCode: 32}
checkWord(e)


e = {keyCode: 32}
ix = 0
while(1){
        a = document.getElementById("textArea").childNodes[ix].textContent
    console.log(a, ix, document.getElementById("textArea").childNodes[ix])
    document.getElementById("textInput").value = a
    ix++;
    checkWord(e)
}

e = {keyCode: 32}
ix = 0
while(document.getElementById("textArea").childNodes.length){
        a = document.getElementById("textArea").childNodes[ix].textContent
    console.log(a, ix, document.getElementById("textArea").childNodes[ix])
    document.getElementById("textInput").value = a
    ix++;
    checkWord(e)
}





ix = 0;
const e = {keyCode: 32}
let text = document.getElementById("textArea").childNodes[ix].textContent
const o = {
                "input": text.split(String.fromCharCode(e.keyCode))[0].toLowerCase()
            }
const res = function(response) {
                document.getElementById('falseWcounter').innerHTML = response.false_word;
                document.getElementById('trueWcounter').innerHTML = response.true_word;
    
                a = document.getElementById("textArea").childNodes[ix].textContent
                console.log(a, ix, document.getElementById("textArea").childNodes[ix])
                document.getElementById("textInput").value = a
                ix++;
                text = $("input[id='textInput']")[0].value;
                postWithFunction("score", res, o );
            }



postWithFunction("score", res, o );









while (1) {
    xhr = new XMLHttpRequest()

    var xhttp = new XMLHttpRequest();
    /* xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        // Typical action to be performed when the document is ready:
        alert(xhttp.responseText);
        }
    }; */


    /* xhttp.onload = function() {
    alert(`Loaded: ${xhttp.status} ${xhttp.response}`);
    };

    xhttp.onerror = function() {
    alert("Request failed");
    };
    */

    xhttp.open("POST", "posts.php?action=score", true);
    xhttp.send("dataaaaaa");

}







