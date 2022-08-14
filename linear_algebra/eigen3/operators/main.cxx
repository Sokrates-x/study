#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// select
	Eigen::Matrix3i m;	
	m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	m = (m.array() > 5).select(-m, m);

	m.diagonal(0);
	m.diagonal(1);
	m.diagonal(-1);

	// Jocobi Rotation
	Eigen::Matrix2f mat;	
	mat << 1, 2, 3 , 4;
	mat = (mat + mat.adjoint()).eval();	
	Eigen::JacobiRotation<float> J;
	J.makeJacobi(2, 5, 8); // same as bellow
	//J.makeJacobi(mat, 0, 1);
	mat.applyOnTheLeft(0, 1, J.adjoint());				
	mat.applyOnTheRight(0, 1, J);	

	// Givens Rotation	
	Eigen::Vector2f vec;
	vec << 3.0, 4.0;
	Eigen::JacobiRotation<float> G; 
	G.makeGivens(vec.x(), vec.y());
	vec.applyOnTheLeft(0, 1, G.adjoint());

	// Jocabi Rotation
	Eigen::JacobiRotation<float> JJ(0.8, 0.6);
	vec.applyOnTheLeft(0, 1, JJ.adjoint());	

	// Household Sequeue
	Eigen::Vector3f va, vb, vc;
	va << 1, 2, 3;
	vb << 0, 1, 2;
	vc << 0, 0, 1;
	Eigen::Vector3f h;
	h << 0.3, 0.4, 0.3;
	auto H0 = Eigen::Matrix3f::Identity() - h(0) * va * va.transpose();
	auto H1 = Eigen::Matrix3f::Identity() - h(1) * vb * vb.transpose();
	auto H2 = Eigen::Matrix3f::Identity() - h(2) * vc * vc.transpose();

	auto res = H0 * H1 * H2;

	std::cout << res << std::endl;
	return 0;
}
