#include <iostream>

inline void f(int &a, int b, int c = 0);

void f(int &a, int b, int c)
{
	++a;
	return;
}

constexpr int f(int a)
{
	return a*2;
}

int main(int argc, char **argv)
{
	int a = 1, b, c;	
	f(a);
	f(a, b);
	f(a, b, c);

	int arr[f(a)];
	arr[1] = 1;
	int arr2[a];

	int *p = new int[a];
	int arr3[sizeof(arr2)];
	std::cout << sizeof arr2 << std::endl;
	return 0;
}
