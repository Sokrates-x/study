#include "screen.h"
#include <iostream>

void Screen::display() const
{
	for (int i = 0; i != pos_y_; ++i)
		std::cout << std::endl;
	for (int i = 0; i != pos_x_; ++i)
		std::cout << " ";
	for (int i = 0; i != width_; ++i)
		std::cout << "*";
	std::cout << std::endl;
	for (int i = 0; i != height_ - 2; ++i)
	{
		for (int i = 0; i != pos_x_; ++i)
			std::cout << " ";
		std::cout << "*";
		for (int i = 0; i != width_ - 2; ++i) 
			std::cout << bar_;
		std::cout << "*" << std::endl;
	}

	for (int i = 0; i != pos_x_; ++i)
		std::cout << " ";
	for (int i = 0; i != width_; ++i)
		std::cout << "*";
	std::cout << std::endl;
}
