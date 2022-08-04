#include <iostream>
#include <sys/file.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int, char **)
{
	
	int pid = fork();	
	int fd = open("data", O_RDWR);
	if (fd < 0)
		std::cerr << "Open File Failed" << std::endl;

	switch (pid) {
	case -1:
		break;
	case 0:
		lockf(fd, F_LOCK, 0);		
		lseek(fd, 0, SEEK_END);
		for (int i = 0; i < 100; ++i) {
			lseek(fd, 0, SEEK_END);
			write(fd, "\nRead in 2022-08-04.", 20); 
		}
		lseek(fd, 0, 0L);
		lockf(fd, F_ULOCK, 0);
		break;
	default:
		lockf(fd, F_LOCK, 0);		
		lseek(fd, 0, SEEK_END);
		for (int i = 0; i < 100; ++i) {
			write(fd, "\nRead in 2022-08-03.", 20); 
		}
		lseek(fd, 0, 0L);
		lockf(fd, F_ULOCK, 0);
		wait(nullptr);	
	}
	close(fd);
	return 0;
}
