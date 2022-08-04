#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(int, char **)
{
	int fd[2];	
	pipe(fd);
	int pid = fork();	

	switch (pid) {
	case -1:
		break;
	case 0:
		dup2(0, fd[0]);
		execlp("sort", "sort", '\0');
	default:
		wait(nullptr);
	}
	
	return 0;
}
