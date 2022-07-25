#ifndef FIND_MAX_SUBARR_H
#define FIND_MAX_SUBARR_H

#include <tuple>
#include <iterator>

template <typename T>
std::tuple<T, T, typename std::iterator_traits<T>::value_type> 
	find_max_subarr(T, T);

#include "find_max_subarr_i.h"

#endif
