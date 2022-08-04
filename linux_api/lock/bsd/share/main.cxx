#include <iostream>
#include <sys/file.h>
#include <unistd.h>
#include <iterator>
#include <functional>

int main(int, char **)
{
	char buffer[100];	

	// open
	int fd = open("data", O_RDONLY);			
	int file_len = lseek(fd, 0, SEEK_END);
	// lock
	flock(fd, LOCK_SH);
	// read
	lseek(fd, 0, 0);
	while (lseek(fd, 0, SEEK_CUR) < file_len) {
		read(fd, buffer, 1);
		std::copy(std::begin(buffer), std::end(buffer),
			std::ostream_iterator<char>(std::cout, ""));
	}
	// unlock
	lseek(fd, 0, 0);	
	flock(fd, LOCK_UN);
	// close
	close(fd);
	std::cout << std::endl;
	return 0;
}
