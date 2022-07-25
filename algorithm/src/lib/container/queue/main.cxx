#include "queue.h"
#include <iostream>

int main(int, char **)
{
	Queue<int> q;
	for (int i = 0; i < 30; ++i)
		q.enqueue(i);

	for (int i = 0; i < 25; ++i)
		std::cout << q.dequeue() << std::endl;

	return 0;
}
