#include <iostream>
#include <unistd.h>
#include <sys/file.h>

int main(int, char **)
{
	int fd = open("data", O_RDWR);

	flock(fd, LOCK_EX);
	for (int i = 0; i < 100; ++i) {
		lseek(fd, 0, SEEK_END);
		write(fd, "SHARE\n", 6);
	}	

	flock(fd, LOCK_UN);	
	close(fd);

	return 0;
}
