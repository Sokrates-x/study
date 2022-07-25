#include "find_max_subarr.h"

template <typename RandAccIter>
std::tuple<RandAccIter, RandAccIter, typename 
	std::iterator_traits<RandAccIter>::value_type> find_max_subarr
	(RandAccIter beg, RandAccIter end)
{
	// end condition
	if (end - beg <= 1)
		return std::make_tuple(beg, end, *beg);

	// divide
	auto ltuple = find_max_subarr(beg, beg + (end - beg)/2);	
	auto rtuple = find_max_subarr(beg + (end - beg)/2, end);	

	// cross sub array
	auto lmax_iter = beg + (end - beg)/2 - 1;
	auto lmax = *lmax_iter;
	auto lsum = *lmax_iter;
	for (auto l_iter = beg + (end - beg)/2 - 2; l_iter >= beg; --l_iter)
	{
		lsum += *l_iter;	
		if (lsum > lmax)
		{
			lmax_iter = l_iter;
			lmax = lsum;
		}
	}

	auto rmax_iter = beg + (end - beg)/2;
	auto rmax = *rmax_iter;
	auto rsum = *rmax_iter;
	for (auto r_iter = beg + (end - beg)/2 + 1; r_iter < end; ++r_iter)
	{
		rsum += *r_iter;	
		if (rsum > rmax)
		{
			rmax_iter = r_iter;
			rmax = rsum;
		}
	}

	// conquer
	return std::get<2>(ltuple) > std::get<2>(rtuple) ? 
			std::get<2>(ltuple) > lmax + rmax ? ltuple : 
			std::make_tuple(lmax_iter, ++rmax_iter, lmax + rmax) : 
			std::get<2>(rtuple) > lmax + rmax ? rtuple : 
			std::make_tuple(lmax_iter, ++rmax_iter, lmax + rmax);
}
