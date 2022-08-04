#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

int main(int, char **)
{
	auto fd = fopen("sfifo", "w");
	fputs("hello sfifo.\n", fd);
	fclose(fd);
	return 0;
}
