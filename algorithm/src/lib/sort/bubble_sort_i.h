#include "bubble_sort.h"
#include <utility>

template<typename BidirIter>
void bubble_sort(BidirIter beg, BidirIter end)
{
	auto b = beg;
	for (auto b = beg; b != end; ++b)
	{
		for (auto e = end - 1; e != b; --e)
			if (*e < *(e - 1))
				std::swap(*e, *(e - 1));

	}

	return;
}
