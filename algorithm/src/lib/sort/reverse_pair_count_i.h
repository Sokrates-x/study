#include "reverse_pair_count.h"
#include <vector>
#include <functional>
#include <iterator>

template<typename RandAccIter>
void reverse_pair_count(RandAccIter beg, RandAccIter end, int &n)
{
	// end condition
	if (end - beg <= 1)
		return;
	// split	
	reverse_pair_count(beg, beg + (end - beg)/2, n);
	reverse_pair_count(beg + (end - beg)/2, end, n);

	// copy 
	std::vector<typename std::iterator_traits<RandAccIter>::value_type> lv;	
	std::vector<typename std::iterator_traits<RandAccIter>::value_type> rv;	
	std::copy(beg, beg + (end - beg)/2, std::back_inserter(lv));
	std::copy(beg + (end - beg)/2, end, std::back_inserter(rv));

	// merge count reverse pairs
	for (auto li = lv.begin(), ri = rv.begin(); li != lv.end(); ++li)	
		for (; *li > *ri && ri != rv.end(); n += lv.end() - li, ++ri);
	// merge sort
	for (auto li = lv.begin(), ri = rv.begin(); beg != end;
		li == lv.end() || *li > *ri && ri != rv.end() ? 
		*beg++ = *ri++ : *beg++ = *li++);
	return;
}

template<typename RandAccIter>
int reverse_pair_count(RandAccIter beg, RandAccIter end)
{
	int i = 0;
	reverse_pair_count(beg, end, i);
	return i;
}
