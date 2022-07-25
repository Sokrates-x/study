#include "strategy.h"
#include <iostream>

void StrategyA::exec() {
	std::cout << "Strategy A executing..." << std::endl;
}

void StrategyB::exec() {
	std::cout << "Strategy B executing..." << std::endl;
}

void StrategyC::exec() {
	std::cout << "Strategy C executing..." << std::endl;
}
