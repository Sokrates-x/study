#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <memory>

template <typename T>
class Matrix;

template <typename T>
Matrix<T> operator+(const Matrix<T> &, const Matrix<T> &);

template <typename T>
Matrix<T> operator-(const Matrix<T> &, const Matrix<T> &);

template <typename T>
class Matrix
{

public:
	// types
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef size_t size_type; 
	typedef ptrdiff_t difference_type;

	// friends
	friend Matrix<T> operator+<T>(const Matrix<T> &, const Matrix<T> &);
	friend Matrix<T> operator-<T>(const Matrix<T> &, const Matrix<T> &);

	// ctors
	Matrix() = delete;
	explicit Matrix(size_t sz, size_t rsz = 1) : row_size_(rsz)
		{ alloc_and_fill(sz, T()); }
	Matrix(size_t sz, const T &t, size_t rsz = 1) : row_size_(rsz)
		{ alloc_and_fill(sz, t); }

	// copy ctors
	Matrix(const Matrix &);	
	Matrix &operator=(const Matrix &) &;

	// move ctors
	Matrix(Matrix &&);
	Matrix &operator=(Matrix &&) &;

	// dtors
	~Matrix();

	// method
	iterator begin() const { return start_; }
	iterator end() const { return finish_; }

	const T *cbegin() const { return start_; }
	const T *cend() const { return finish_; }

	size_t row_sz() const { return row_size_; }
	size_t size() const { return size_; }
	
protected:
	// allocate & fill with T
	void alloc_and_fill(size_t, const value_type&);
	void alloc_and_copy(iterator, iterator);
	// destroy & deallocate
	void free();

	// allocator
	std::allocator<value_type> alloc;

private:

	iterator start_;
	iterator finish_;
	// real size = capcity because of no size change avialiable
	size_type size_;
	size_type row_size_;
};

#include "matrix_i.h"

#endif
