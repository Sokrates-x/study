#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// join vectors
	Eigen::ArrayXi vec1(3), vec2(4);	
	vec1 << 1, 2, 3;
	vec2 << 1, 2, 3, 4;
	Eigen::ArrayXi res1(12);	
	res1 << vec1, vec2, 1, 2, 3, 4, 5;

	// join matrice with order left to right top to bot
	Eigen::MatrixXi mat(2, 2);	
	Eigen::VectorXi v1(2);
	v1 << 10, 20;
	Eigen::RowVectorXi v2(2);
	v2 << 30, 40;
	Eigen::MatrixXi res2(3, 3);	
	mat << 1, 2, 3, 4;
	res2 << mat, v1, v2, 1;

	// Partial Initialise
	Eigen::Matrix3i res3;
	res3.row(0) << 1, 2, 3;
	res3.block(1, 0, 2, 2) << 4, 5, 7, 8;
	res3.col(2).tail(2) << 6, 9;
	
	// Array with zeros
	Eigen::Array3i::Zero();
	Eigen::ArrayXi::Zero(3);
	Eigen::ArrayXXi::Zero(3, 4);

	// Constant LinSpaced
	Eigen::Array3i::Constant(3);
	Eigen::ArrayXf::LinSpaced(10, 1, 20);
	
	//
	Eigen::MatrixXi magic(9, 9);
	magic.topRightCorner(3, 3) = Eigen::MatrixXi::Identity(3, 3);
	magic.bottomLeftCorner(3, 3) = Eigen::MatrixXi::Identity(3, 3);
	magic.block(3, 0, 3, 3).col(0) = Eigen::ArrayXi::Ones(3);
	magic.block(0, 3, 3, 3).row(0) = Eigen::ArrayXi::Ones(3);
	magic(Eigen::last, Eigen::seq(3, 5)) = Eigen::ArrayXi::Ones(3);
	magic(Eigen::seq(3, 5), Eigen::last) = Eigen::ArrayXi::Ones(3);
	magic(Eigen::seq(2, 0, -1), Eigen::seq(0, 2)) = 
		Eigen::MatrixXi::Identity(3, 3);
	magic.bottomRightCorner(3, 3)(Eigen::seq(2, 0, -1), Eigen::seq(0, 2)) =
		Eigen::MatrixXi::Identity(3, 3);
	magic.block(2, 2, 5, 5).col(0).setOnes();
	magic.block(2, 2, 5, 5).col(4).setOnes();
	magic.block(2, 2, 5, 5).row(0).setOnes();
	magic.block(2, 2, 5, 5).row(4).setOnes();
	magic(4, 4) = 1;

	auto res = Eigen::MatrixXi::Constant(3, 3, 1);	

	//
	std::cout << magic << std::endl;

	return 0;
}
