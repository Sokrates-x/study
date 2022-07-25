#include <utility>

template <typename T>
void insert_sort(T beg, T end)
{
	if (end - beg <= 1)
		return;
	T curr_ = beg;
	while (++curr_ != end)
	{
		T i = beg;
		for (;i < curr_ && *i <= *curr_; ++i);
		while (i < curr_)
			std::swap(*i++, *curr_);
	}	
	return;
}
