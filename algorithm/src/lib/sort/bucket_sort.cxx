#include "bucket_sort.h"
#include <vector>
#include "insert_sort.h"

void bucket_sort(int *beg, int *end)
{

	std::vector<int> bucket[10];

	// put into buckets
	for (int i = 0; i != end - beg; ++i)
		bucket[*(beg + i)/10].push_back(*(beg + i));

	// insert_sort as well as link buckets
	for (int i = 0; i != 10; ++i)
	{
		insert_sort(bucket[i].begin(), bucket[i].end());
		for (auto m : bucket[i])
			*beg++ = m;
	}
}
