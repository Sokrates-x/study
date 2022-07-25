#ifndef HAS_TWO_ADDED_H
#define HAS_TWO_ADDED_H

#include <iterator>

template <typename T>
bool has_two_added(T, T, typename std::iterator_traits<T>::value_type);


#include "has_two_added_i.h"
#endif
