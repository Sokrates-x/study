#include <iostream>
#include <unistd.h>

int main(int, char **)
{
	//execl("/bin/ls", ".", '\0');

	char x[]("ls");
	char x1[]("/bin");
	char x2[]("\0");
	char *y[]{x, x1, x2};
	execv("/bin/ls", y);
	return 0;
}
