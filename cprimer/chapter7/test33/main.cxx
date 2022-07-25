#include <iostream>

class Screen;

class WindMgr {
public:
	void clear(const Screen& s);
};

class Screen {
public:
	friend void WindMgr::clear(const Screen& s);

private:
	int a = 2;
};

void WindMgr::clear(const Screen& s)
{
	std::cout << s.a << std::endl;
}

int main(int, char **)
{
	WindMgr().clear(Screen());	
	return 0;
}
