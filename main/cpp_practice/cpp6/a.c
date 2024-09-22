#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	char buff[55] = {};

	if(pipe(fd))
	{
		perror("pipe");
		exit(1);
	}
	if (dup2(fd[1], 1))
	{
		// dprintf(1, "%d, %d\n", fd[1], fd[0]);
		// perror("dup2");
		// exit(1);
	}
	// if (fork() == 0){
	// 	dup2(fd[1], 1);
	// 	write(1, "hello", 5);
	// 	exit(0);
	// }

	// close(x);
	close(fd[1]);
	write(1, "hnuello", 5);
	// close(1);
	// dprintf(2, "fdartsarst");
	read(fd[0], buff, 5);
	// dprintf(2, "fdartsarst");
	// close(fd[0]);
	dprintf(2, "buff: %s\n", buff);
	return 0;
}
