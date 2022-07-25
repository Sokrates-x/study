#include "screen.h"
#include <string>

int main(int argc, char **argv)
{
	int x = std::stoi(std::string(*++argv));	
	int y = std::stoi(std::string(*++argv));
	int h = std::stoi(std::string(*++argv));
	int w = std::stoi(std::string(*++argv));
	int c = std::string(*++argv)[0];
	Screen s(x, y, h, w, c);
	s.display();
	return 0;
}
