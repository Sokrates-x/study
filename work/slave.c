#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	// pipe fd
	int pipefd[2];	

	// creat pipe & check
	if (pipe(pipefd) == -1) {
		perror("Pipe Failed.");
		return -1;
	}

	int pid = fork();

	switch (pid) {
		case -1:
			perror("Fatal Error: Fork Faialed.");
			abort();
			break;

		case 0:
			close(pipefd[0]);
			// map stdout to pipe fd1
			if(dup2(pipefd[1], fileno(stdout)) < 0)	
			{
				perror("Map STDOUT to pipe Failed.");
			}

			//
			if (execl("/root/work/hello", "./hello", "", NULL) == -1)
			{
				perror("Fatal Error: getsends Failed.");
				abort();
			}
			break;

		default:
			// 
			printf("Debug Start\n");
			close(pipefd[1]);

			// creat socket id
			int sid = socket(AF_INET, SOCK_STREAM, 0);
			if (sid < 0)
			{
				perror("Fatal Error: Creat Socket Failed.");
				abort();
			}
		
			// addr
			struct in_addr adi;
			adi.s_addr = inet_addr("127.0.0.1");
		
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			// port
			addr.sin_port = htons(19931);
			// ip addr
			addr.sin_addr = adi;
		
			// connect
			if (connect(sid, (struct sockaddr *)(&addr), sizeof(addr)) == -1)
			{
				perror("Fatal Error: Connect to Host Failed.");
				abort();
			}
		
			char buffer[1];
		
			char flag = 'r';
		
			// read from pipe & send to host
			while(read(pipefd[0], buffer, 1) > 0 && flag != 'q')
			{
				send(sid, buffer, 1, 0);
				recv(sid, &flag, 1, MSG_DONTWAIT);
			}
		
			if (flag == 'q') 
			{
				printf("Quited by host.\n");
			}
		
			// close pipe
			close(pipefd[0]);
			printf("Debug Ended\n");
			break;
	}

	return 0;
}
