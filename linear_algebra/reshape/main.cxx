#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// it seems that it's stored by cols
	Eigen::MatrixXi mat(3, 2);	
	mat.reshaped() << Eigen::ArrayXi::LinSpaced(6, 1, 6);

	//auto res = mat.reshaped(2, 3);
	auto res = mat.reshaped<Eigen::RowMajor>(2, 3);
	mat.resize(2, 3);		
	// mat & res has alias	
	std::cout << mat << std::endl;	
	std::cout << res << std::endl;
	return 0;
}
