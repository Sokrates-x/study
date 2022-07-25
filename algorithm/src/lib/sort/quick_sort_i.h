#include "quick_sort.h"

template <typename RandAccIter>
void quick_sort(RandAccIter beg, RandAccIter end)
{
	if (end - beg <= 1)
		return;
	// 
	auto m = beg;
	for (auto curr = beg + 1; curr != end; ++curr)
	{
		if (*curr < *m)
		{
			std::swap(*curr, *(m + 1));
			std::swap(*(m + 1), *m);
			++m;
		}
	}
	quick_sort(beg, m);
	quick_sort(m + 1, end);
}
