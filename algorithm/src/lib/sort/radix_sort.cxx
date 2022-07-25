#include "radix_sort.h"

#include <tuple>

#define COUNTING_SORT(i) \
		for (int j = 0; j != end - beg; ++j)\
		{\
			++base[std::get<i>(A[j])];\
		}\
		for (int k = 1; k != 10; ++k)\
		{\
			base[k] += base[k - 1];	\
		}\
		for (int l = end - beg - 1; l >=0; --l)\
		{\
			B[base[std::get<i>(A[l])] - 1] = A[l];\
			--base[std::get<i>(A[l])];\
		}\
		for (int m = 0; m < end - beg; ++m)\
		{\
			A[m] = B[m];\
		}\
		for (int n = 0; n != 10; ++n)\
		{\
			base[n] = 0;\
		}

void radix_sort(int *beg, int *end)
{
	std::tuple<int, int, int, int, int, int> A[end - beg];
	std::tuple<int, int, int, int, int, int> B[end - beg];

	for (int i = 0; i != end - beg; ++i)
	{
		A[i] = std::make_tuple(*(beg + i), *(beg + i) % 10, *(beg + i) / 10
			% 10, *(beg + i) / 100 % 10, *(beg + i) / 1000 % 10, 
			*(beg + i) /10000 % 10);
		B[i] = A[i];
	}
	
	// counting sort
	int base[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	

	COUNTING_SORT(1);
	COUNTING_SORT(2);
	COUNTING_SORT(3);
	COUNTING_SORT(4);
	COUNTING_SORT(5);

	for (int i = 0; i != end - beg; ++i)
	{
		*(beg + i) = std::get<0>(A[i]);
	}
}
