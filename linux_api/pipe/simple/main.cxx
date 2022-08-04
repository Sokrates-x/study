#include <unistd.h>
#include <iostream>
#include <iterator>
#include <functional>

int main(int, char **)
{
	int fd[2];		
	pipe(fd);
	int pid = fork();
	char buffer[30];

	switch (pid) {
	case -1:
		std::cerr << "Fork Failed" << std::endl;
		break;
	case 0:
		close(fd[0]);
		write(fd[1], "hello, pipe", 12); 
		exit(0);
		break;
	default:
		close(fd[1]);	
		read(fd[0], buffer, 12);
		std::copy(std::begin(buffer), std::end(buffer), 
			std::ostream_iterator<char>(std::cout, ""));
		std::cout << std::endl;
	}
	return 0;
}
