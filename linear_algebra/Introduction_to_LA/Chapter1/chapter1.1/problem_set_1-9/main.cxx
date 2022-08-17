#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// problem 1 vector addition
	std::cout << "Problem 1\n";
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
	std::cout << "Problem 2\n";
	Eigen::Vector2i v2_lhs, v2_rhs;
	v2_lhs << 4, 1;
	v2_rhs << -2, 2;
	auto v2_res_p = v2_lhs + v2_rhs;
	auto v2_res_m = v2_lhs - v2_rhs;
	std::cout << v2_res_p.transpose() << '\n' << v2_res_m.transpose() << 
		std::endl;

	// problem 3
	std::cout << "Problem 3\n";
	Eigen::Vector2f v3_w_a_v, v3_w_m_v;	
	v3_w_a_v << 5, 1;
	v3_w_m_v << 1, 5;
	auto v3_w = (v3_w_a_v + v3_w_m_v) / 2;
	auto v3_v = (v3_w_a_v - v3_w_m_v) / 2;
	std::cout << v3_w.transpose() << '\n' << v3_v.transpose() << std::endl;

	// problem 4
	std::cout << "Problem 4\n";
	Eigen::Vector2i v4_v, v4_w;
	v4_v << 2, 1;
	v4_w << 1, 2;
	auto v4_res = v4_v * 3 + v4_w;
	std::cout << v4_res.transpose() << std::endl;

	// problem 5
	std::cout << "Problem 5" << std::endl;
	Eigen::Vector3f v5_u, v5_v, v5_w;		
	v5_u << 1, 2, 3;
	v5_v << -3, 1, -2;
	v5_w << 2, -3, -1;
	auto v5_u_v_w = v5_u + v5_v + v5_w;
	auto v5_2u_2v_w = 2 * v5_u + 2 * v5_v + v5_w;

	Eigen::MatrixXf v5_uv(3, 2);
	v5_uv(Eigen::all, 0) = v5_u; 
	v5_uv(Eigen::all, 1) = v5_v; 

	// auto does NOT work
	// need explicit type consevation
	Eigen::Vector2f v5_res_cd = v5_uv.fullPivLu().solve(v5_w);	
	
	std::cout << "u + v + w = " << v5_u_v_w.transpose() << '\n';
	std::cout << "2u + 2v + w = " << v5_2u_2v_w.transpose() << '\n';
	std::cout << "c d = " << v5_res_cd.transpose() << '\n';
	
	// Problem 6	
	std::cout << "Problem 6" << std::endl;
	Eigen::Vector3f v6_u, v6_v, v6_w, v6_w2;
	v6_u << 1, -2, 1;
	v6_v << 0, 1, -1;
	v6_w << 3, 3, -6;
	v6_w2 << 3, 3, 6;
	Eigen::MatrixXf v6_uv(3, 2);
	v6_uv(Eigen::all, 0) = v6_u;
	v6_uv(Eigen::all, 1) = v6_v;
	Eigen::Vector2f v6_res_cd = v6_uv.fullPivLu().solve(v6_w);
	bool v6_flag = v6_u.cross(v6_v).dot(v6_w2) == 0 ? true : false;
	std::cout << "c d = " << v6_res_cd.transpose() << '\n';
	std::cout << "Possible ? " << std::boolalpha << v6_flag << std::endl;

	// problem 7
	std::cout << "Problem 7" << std::endl;
	Eigen::Vector2i v7_u, v7_v;
	v7_u << 2, 1;
	v7_v << 0, 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			std::cout << i << "u + " << j <<"v =  " << (i * v7_u + j * 
				v7_v).transpose() << '\n';
	}

	// Problem 8
	std::cout << "Problem 8" << std::endl;
	std::cout << "v - w or w - v\n2v or 2w" << std::endl;	

	// Problem 9 
	std::cout << "Problem 9" << std::endl;
	Eigen::Vector2i v9_p1, v9_p2, v9_p3;
	v9_p1 << 1, 1;
	v9_p2 << 4, 2;
	v9_p3 << 1, 3;
	auto v9_p4_1 = v9_p2 - v9_p1 + v9_p3 - v9_p1;
	auto v9_p4_2 = v9_p1 - v9_p2 + v9_p3 - v9_p2;
	auto v9_p4_3 = v9_p1 - v9_p3 + v9_p2 - v9_p3;
	std::cout << "p1 p4 as diagonal: p4 = " << v9_p4_1.transpose() << '\n';
	std::cout << "p2 p4 as diagonal: p4 = " << v9_p4_2.transpose() << '\n';
	std::cout << "p3 p4 as diagonal: p4 = " << v9_p4_3.transpose() << '\n';

	return 0;
}
