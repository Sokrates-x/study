#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>
#include <vector>
#include <set>
#include <deque>


int main(int, char **)
{
	Eigen::MatrixXi mat(4, 5);
	mat.reshaped() = Eigen::VectorXi::LinSpaced(20, 1, 20);
	
	// slice vs block
	assert(mat(Eigen::seq(1,2), Eigen::seq(1,2)) == mat.block(1, 1, 2, 2));

	// with last
	mat(Eigen::seq(0, Eigen::last), Eigen::seqN(0, 5));	

	// with all	
	mat(Eigen::all, Eigen::all);	

	// with increase
	mat(Eigen::seq(0, 3, 2), Eigen::seq(0, 4, 2));
	
	// with last & + - /	
	mat(Eigen::seq(0, Eigen::last/2), Eigen::seq(0, Eigen::last/3));

	auto vec = Eigen::VectorXi::LinSpaced(9, 1, 9);
	vec.tail(3);
	vec(Eigen::seq(Eigen::last/2, Eigen::last));

	// lastN
	vec(Eigen::lastN(3));

	// compile fixed size for optimal
	mat(Eigen::seq(0, 3, Eigen::fix<2>), Eigen::seq(4, 0, Eigen::fix<-2>));

	// decrese
	vec(Eigen::seqN(Eigen::last, 3, Eigen::fix<-1>));
	vec(Eigen::lastN(3).reverse());

	// by a vector or array of indices
	std::vector<int> ind { 2, 0, 1 };
	mat(ind, ind);
	// ArrayXi is okay
	Eigen::ArrayXi ind2(3);
	ind2 << 2, 0, 1;
	// int[] is okay
	int ind3[3] = { 2, 0, 1 };
	// set is not okay because the increse of index is not linear 
	// std::set ind4(std::begin(ind3), std::end(ind3));
	// deque is okay
	std::deque<int> ind4(ind.begin(), ind.end());
	mat(ind4, ind4);
	
	// padding form back
	struct pad {
		Eigen::Index size() const { return out_size; }
		Eigen::Index operator[](Eigen::Index i) const {
			return i > in_size - 1 ? in_size - 1  : i;
		}
		Eigen::Index in_size, out_size;
	};	

	auto res = mat(pad{4, 6}, pad{5, 6});

	std::cout << res << std::endl;
	return 0;
}
