#include "has_two_added.h"
#include "sort.h"

#include <iterator>
#include <functional>
#include <vector>

template <typename RandAccIter>
bool has_two_added(RandAccIter beg, RandAccIter end, 
	typename std::iterator_traits<RandAccIter>::value_type sum)
{
	// merge sort
	merge_sort(beg, end);
	// find 
	for (auto b = beg, e = end - 1; b != e; ++b)
	{
		while (*b + *e > sum)
			--e;
		if (*b + *e == sum)
			return true;
	}
	return false;
}
