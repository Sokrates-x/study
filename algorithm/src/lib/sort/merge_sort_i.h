#include "merge_sort.h"
#include <iterator>
#include <functional>
#include <vector>

template <typename RandAccIter>
void merge_sort(RandAccIter beg, RandAccIter end)
{
	if (end - beg <= 1)	
		return;
	// re
	merge_sort(beg, beg + (end - beg)/2);
	merge_sort(beg + (end - beg)/2, end);
	// copy
	std::vector<typename std::iterator_traits<RandAccIter>::value_type> lv;
	std::vector<typename std::iterator_traits<RandAccIter>::value_type> rv;
	std::copy(beg, beg + (end - beg)/2, std::back_inserter(lv));
	std::copy(beg + (end - beg)/2, end, std::back_inserter(rv));
	// merge
	for (auto li = lv.begin(), ri = rv.begin(); beg != end;
		li == lv.end() || *li > *ri && ri != rv.end() ? 
		*beg++ = *ri++ : *beg++ = *li++);
	return;
}
