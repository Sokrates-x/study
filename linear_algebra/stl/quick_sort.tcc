#ifndef QUICK_SORT_TCC
#define QUICK_SORT_TCC 1

#include <algorithm>
#include <iterator>

template <typename ForwardIter>
void quickSort(ForwardIter first, ForwardIter last)
{
	typedef typename std::iterator_traits<ForwardIter>::value_type value_type;
	if (first == last)
		return;
	auto pivot = *first;

	auto lower = std::partition(first, last, [pivot] (value_type val) { 
		return val < pivot; });

	auto upper = std::partition(first, last, [pivot] (value_type val) { 
		return !(pivot < val); });

	quickSort(first, lower);
	quickSort(upper, last);
}

#endif // QUICK_SORT_TCC
