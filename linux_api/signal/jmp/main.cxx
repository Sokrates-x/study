#include <iostream>
#include <unistd.h>
#include <setjmp.h>

int main(int, char **)
{
	bool flag = false;
	jmp_buf jb;
	int jmp = setjmp(jb);
	std::cout << "Do Sth." << std::endl;
	flag = !flag;
	if (flag) 
		longjmp(jb, jmp);
	return 0;	
}
