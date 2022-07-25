#include <vector>
#include <iostream>

int f(int, int)
{
	return 1;
}

std::vector<decltype(f) *> dv;

typedef int PF(int, int);
std::vector<PF *> tv;

using PFF = int(int, int);
std::vector<PFF *> uv;

std::vector<int (*)(int, int)> v;

int main(int argc, char **argv)
{
	dv.push_back(f);	
	tv.push_back(f);	
	uv.push_back(f);	
	v.push_back(f);	
	return 0;
}
