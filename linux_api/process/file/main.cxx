#include <iostream>
#include <iterator>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <functional>

int main(int, char **)
{
	int pid, fd;
	char buff[10];
	fd = open("data", O_RDONLY);
	read(fd, buff, 10);
	int pos = lseek(fd, 0, SEEK_CUR);
	std::copy(std::begin(buff), std::end(buff), std::ostream_iterator<char>(
		std::cout, ""));
	std::cout << " " << pos << std::endl;	
	pid = fork();

	switch (pid) {
	case -1:
		std::cout << "Fork Failed" << std::endl;
		break;
	case 0:
		std::cout << "Child." << std::endl;	
		read(fd, buff, 10);
		pos = lseek(fd, 0, SEEK_CUR);
		std::copy(std::begin(buff), std::end(buff), 
			std::ostream_iterator<char>(std::cout, ""));
		std::cout << " " << pos << std::endl;	
		break;
	default:
		wait(NULL);
		read(fd, buff, 10);
		pos = lseek(fd, 0, SEEK_CUR);
		std::copy(std::begin(buff), std::end(buff), 
			std::ostream_iterator<char>(std::cout, ""));
		std::cout << " " << pos << std::endl;	
	}

	fcntl(fd, F_SETFD, 0);
	close(fd);
	return 0;
}
