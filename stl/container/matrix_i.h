#include "matrix.h"
#include <cassert>
#include <iostream>

template <typename T>
void Matrix<T>::alloc_and_fill(size_t sz, const value_type& val)
{
	start_ = alloc.allocate(sz);
	std::uninitialized_fill_n(start_, sz, val);
	finish_ = start_ + sz;
	size_ = sz;
}

template <typename T>
void Matrix<T>::alloc_and_copy(iterator b, iterator e)
{
	size_ = e - b;
	start_ = alloc.allocate(size_);
	std::uninitialized_copy(b, e, start_);
	finish_ = start_ + size_;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &m)
{
	alloc_and_copy(m.begin(), m.end());
	row_size_ = m.row_sz();
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &m) &
{
	if (this != &m)
	{
		free();
		alloc_and_copy(m.begin(), m.end());
		row_size_ = m.row_sz();
	}
	return *this;
}

template <typename T>
Matrix<T>::Matrix(Matrix &&m)
{
	start_ = m.begin();
	finish_ = m.end();
	row_size_ = m.row_sz();
	size_ = m.size();
	m.start_ = m.finish_ = nullptr;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix &&m) &
{
	if (this != &m)
	{
		free();
		start_ = m.begin();
		finish_ = m.end();
		row_size_ = m.row_sz();
		size_ = m.size();
		m.start_ = m.finish_ = nullptr;
	}
	return *this;
}

template <typename T>
void Matrix<T>::free()
{
	if (start_ != nullptr)
	{
		while (--finish_ != start_)
			alloc.destroy(finish_);
		alloc.deallocate(start_, size_);
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	free();
}

template <typename T>
Matrix<T> operator+(const Matrix<T> &l, const Matrix<T> &r)
{
	assert(l.size() == r.size() && l.row_sz() == r.row_sz());	
	Matrix<T> sum = l;
	for (auto si = sum.begin(), ri = r.begin(); si != sum.end(); ++si, ++ri)
		*si += *ri;
	return std::move(sum);
}

template <typename T>
Matrix<T> operator-(const Matrix<T> &l, const Matrix<T> &r)
{
	assert(l.size() == r.size() && l.row_sz() == r.row_sz());	
	Matrix<T> sum = l;
	for (auto si = sum.begin(), ri = r.begin(); si != sum.end(); ++si, ++ri)
		*si -= *ri;
	return std::move(sum);
}
