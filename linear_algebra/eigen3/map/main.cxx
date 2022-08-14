#include <iostream>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <iterator>
#include <functional>

int main(int, char **)
{
	// From array to map
	int array[9];
	for (int i = 1; i <= 9; ++i)
		array[i - 1] = i;

	Eigen::Map<Eigen::Matrix<int, 3, 3, Eigen::RowMajor>> res(array);

	
	// c++ arr & map has alias
	int arr2[4];
	Eigen::Map<Eigen::Matrix<int, 2, 2,	Eigen::RowMajor>, Eigen::Unaligned
		, Eigen::Stride<3, 2>> map(arr2);
			
	// map & matrix has alias	
	Eigen::MatrixXi mat(2, 2);
	mat << 1, 2, 3, 4;	
	Eigen::Map<Eigen::Matrix2i> map_mat(&mat(0));	
	map_mat.setOnes();
	// const refer to matrix
	Eigen::Map<const Eigen::Matrix2i> cmap_mat(&mat(0));

	// use placement new to change the mapped array it is a refer relation
	int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Eigen::Map<Eigen::RowVector4i> map_vec(arr3, 4);
	new (&map_vec) Eigen::Map<Eigen::RowVector4i>(arr3 + 4, 4);

	std::copy_n(map_vec.data(), map_vec.size(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;		

	std::copy(map_vec.begin(), map_vec.end(), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}
