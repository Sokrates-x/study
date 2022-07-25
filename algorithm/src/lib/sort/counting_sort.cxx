#include "counting_sort.h"

void counting_sort(int *beg, int *end)
{
	int p[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (auto iter = beg; iter != end; ++iter)
		++p[*iter];

	for (auto i = 1; i != 10; ++i)
	{
		p[i] += p[i - 1];		
	}

	int vec[end - beg];
	for (auto iter = end - 1; iter >= beg; --iter)
	{
		vec[p[*iter] - 1] = *iter;
		--p[*iter];
	}

	for (auto m : vec)
	{
		*beg++ = m;
	}
}
