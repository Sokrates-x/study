#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>
#include <climits>

int main(int, char **)
{
	// NumTraits
	// int is integer
	Eigen::NumTraits<int>::IsInteger;
	// float is NOT integer
	Eigen::NumTraits<float>::IsInteger;

	// int is signed	
	Eigen::NumTraits<int>::IsSigned;
	// float is also signed
	Eigen::NumTraits<float>::IsSigned;

	// int is NOT complex
	Eigen::NumTraits<int>::IsComplex;	
	// std::complex	is complex
	Eigen::NumTraits<std::complex<int>>::IsComplex;

	// int is NOT RequireInitialization	
	Eigen::NumTraits<int>::RequireInitialization;
	// float is also NOT RequireInitialization	
	Eigen::NumTraits<float>::RequireInitialization;
	// std::complex is also NOT RequireInitialization	
	Eigen::NumTraits<std::complex<float>>::RequireInitialization;
	// std::string is RequireInitialization
	Eigen::NumTraits<std::string>::RequireInitialization;

	// long double read cost is 1
	Eigen::NumTraits<long double>::ReadCost;	
	// std::complex read cost is 2
	Eigen::NumTraits<std::complex<float>>::ReadCost;	
		
	// long double add cost is 1
	Eigen::NumTraits<long double>::AddCost;	
	// std::complex add cost is 2
	Eigen::NumTraits<std::complex<float>>::AddCost;	

	// long double mul cost is 1
	Eigen::NumTraits<long double>::MulCost;	
	// std::complex mul cost is 6
	Eigen::NumTraits<std::complex<float>>::MulCost;

	// int epsilon is 0
	Eigen::NumTraits<int>::epsilon();
	// float epsilon is 1e-7
	Eigen::NumTraits<float>::epsilon();
	// long double epsilon is 1e-19
	Eigen::NumTraits<long double>::epsilon();

	// int digits2 is 31
	Eigen::NumTraits<int>::digits();
	// int digits10 is 9
	Eigen::NumTraits<int>::digits10();

	// int min exponent 0
	Eigen::NumTraits<int>::min_exponent();
	// float min exp -125
	Eigen::NumTraits<float>::min_exponent();
	// double min exp -1021
	Eigen::NumTraits<double>::min_exponent();

	// int max exponent 0
	Eigen::NumTraits<int>::max_exponent();
	// float max exp 128
	Eigen::NumTraits<float>::max_exponent();
	// double max exp 1024
	Eigen::NumTraits<double>::max_exponent();

	// int highest
	assert(INT_MAX == Eigen::NumTraits<int>::highest());
	// double highest > 1e308
	Eigen::NumTraits<double>::highest();
	// min
	assert(INT_MIN == Eigen::NumTraits<int>::lowest());	
	assert(Eigen::NumTraits<double>::highest() == 
		-Eigen::NumTraits<double>::lowest());	

	// int infinity is 0 ?	
	Eigen::NumTraits<int>::infinity();	
	// double infinity is inf
	Eigen::NumTraits<double>::infinity();	
	// double quiet_NaN is nan
	Eigen::NumTraits<double>::quiet_NaN();

	// double precision 1e-12
	Eigen::NumTraits<double>::dummy_precision();
	// float precision  1e-5
	auto res = Eigen::NumTraits<float>::dummy_precision();

	std::cout << res << std::endl;
	return 0;
}
