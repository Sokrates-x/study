#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	Eigen::MatrixXi m(3, 4);
	m << 1, 2, 3 ,4 ,5, 6, 7, 8, 9, 10, 11, 12;

	// block(i, j, m, n)
	// ATTENTION: blk will change as matrix changed
	m.block(0, 0, 2, 2);

	// use eval to avoid this
	auto blk = m.block(0, 0, 2, 2).eval();		

	// block<m, n>(i, j)
	m.block<2, 2>(1, 1);

	// WARNING: this has an alias
	// result will NOT be what you want
	m.block<2, 2>(1, 1) = blk;

	//  col & row start from index 0
	m.row(1);	
	m.col(1);

	// Corners
	m.topLeftCorner(2, 2);
	m.bottomLeftCorner<2, 2>();
	m.topRightCorner(2, 2);
	m.bottomRightCorner(2, 2);
	
	// Row Cols
	m.topRows(1);	
	m.bottomRows(1);	
	m.leftCols(1);	
	m.rightCols(1);	

	std::cout << res << std::endl;
	return 0;
}
