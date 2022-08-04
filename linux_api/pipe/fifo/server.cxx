#include <unistd.h>
#include <iostream>
#include <iterator>
#include <functional>
#include <sys/stat.h>
#include <cassert>

int main(int, char **)
{
	char buf[100];	
	//mknod("sfifo", S_IFIFO | 0666, 0); 
	while (true) {
		auto fp = fopen("sfifo", "r");		
		fgets(buf, 100, fp);
		std::copy(std::begin(buf), std::end(buf), 
			std::ostream_iterator<char>(std::cout, ""));
		sleep(1);
		fclose(fp);
	}
	return 0;
}
