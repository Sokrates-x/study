#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// problem 1 vector addition
	// problem 1 a)
	Eigen::Vector3i v1a_lhs, v1a_rhs;
	v1a_lhs << 1, 2, 3;
	v1a_rhs << 3, 6, 9;
	auto v1a_res = v1a_lhs + v1a_rhs;	

	// problem 1 b)
	Eigen::Vector3i v1b_lhs, v1b_rhs;
	v1b_lhs << 1, 0, 0;
	v1b_rhs << 0, 2, 3;
	auto v1b_res = v1b_lhs + v1b_rhs;	

	// problem 1 c)
	Eigen::Vector3i v1c_lhs, v1c_mhs, v1c_rhs;
	v1c_lhs << 2, 0, 0;
	v1c_mhs << 0, 2, 2;
	v1c_rhs << 2, 2, 3;
	auto v1c_res = v1c_lhs + v1c_mhs + v1c_rhs;
	
	std::cout << v1a_res.transpose() << '\n' <<  v1b_res.transpose() << 
		'\n' << v1c_res.transpose() << std::endl;

	// problem 2
	Eigen::Vector2i v2_lhs, v2_rhs;
	v2_lhs << 4, 1;
	v2_rhs << -2, 2;
	auto v2_res_p = v2_lhs + v2_rhs;
	auto v2_res_m = v2_lhs - v2_rhs;
	std::cout << v2_res_p.transpose() << '\n' << v2_res_m.transpose() << 
		std::endl;

	// problem 3
	Eigen::Vector2f v3_w_a_v, v3_w_m_v;	
	v3_w_a_v << 5, 1;
	v3_w_m_v << 1, 5;
	auto v3_w = (v3_w_a_v + v3_w_m_v) / 2;
	auto v3_v = (v3_w_a_v - v3_w_m_v) / 2;
	std::cout << v3_w.transpose() << '\n' << v3_v.transpose() << std::endl;

	// problem 4
	Eigen::Vector2i v4_v, v4_w;
	v4_v << 2, 1;
	v4_w << 1, 2;
	auto v4_res = v4_v * 3 + v4_w;
	std::cout << v4_res.transpose() << std::endl;

	// problem 5
	






	// self adjoint matrices
	Eigen::Matrix2i mat, res;
	mat << 1, 2, 3, 4;
	res = mat.selfadjointView<Eigen::Lower>();	
//	std::cout << res << std::endl;
	return 0;
}
