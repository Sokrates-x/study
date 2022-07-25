#include "heap_sort.h"

template <typename RandAccIter>
void heap_sort(RandAccIter beg, RandAccIter end)
{
	// make heap		
	if (end - beg <= 1)
		return;
	size_t n = 1;
	while (end - beg + 1 > 2*n)
		n*=2;

	//beg + n - 1 --> beg root node
	for (auto i = beg + n - 1; i >= beg; --i)
	{
		// max heapify
		auto j = i;
		for (auto diff = j - beg; j + diff + 1 < end; diff = j - beg)
		{
			auto p = *j;
			auto l = *(j + diff + 1);
			if (j + diff + 2 < end)
			{
				auto r = *(j + diff + 2);			
				if (p >= l && p >= r)
					break;
				if (r <= l)
				{
					std::swap(*j, *(j + diff + 1));
					j = j + diff + 1;
				}
				else
				{
					std::swap(*j, *(j + diff + 2));
					j = j + diff + 2;
				}
			}
			else 
			{
				if (p > l)
					break;
				std::swap(*j, *(j + diff + 1));	
				j = j + diff + 1;
			}
		}
	}
	// heap sort
	auto iter = end - 1;
	while (iter != beg)
	{
		std::swap(*iter--, *beg);
		// max heapify
		auto j = beg;
		for (auto diff = j - beg; j + diff + 1 <= iter; diff = j - beg)
		{
			auto p = *j;
			auto l = *(j + diff + 1);
			if (j + diff + 2 <= iter)
			{
				auto r = *(j + diff + 2);			
				if (p >= l && p >= r)
					break;
				if (r <= l)
				{
					std::swap(*j, *(j + diff + 1));
					j = j + diff + 1;
				}
				else
				{
					std::swap(*j, *(j + diff + 2));
					j = j + diff + 2;
				}
			}
			else 
			{
				if (p > l)
					break;
				std::swap(*j, *(j + diff + 1));	
				j = j + diff + 1;
			}
		}
	}
}
