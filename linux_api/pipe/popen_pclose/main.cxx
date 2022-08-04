#include <iostream>
#include <unistd.h>

int main(int, char **)
{
	char buf[100];
	auto fdin = popen("ls", "r");
	auto fdout = popen("sort", "w");
	fgets(buf, 100, fdin);
	fputs(buf, fdout);
	fgets(buf, 100, fdin);
	fputs(buf, fdout);
	pclose(fdin);
	pclose(fdout);
	return 0;
}
