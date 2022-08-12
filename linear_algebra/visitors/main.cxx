#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	Eigen::MatrixXi m(2, 2);
	m << 1, 2, 3, 4;
	Eigen::Index maxCol, maxRow;
	m.maxCoeff(&maxRow, &maxCol);

	// colwise * rowwise
	m.colwise().maxCoeff();	
	m.rowwise().maxCoeff();

	m.colwise().sum();
	m.rowwise().sum();

	// broadcasting
	Eigen::VectorXi v(2);	
	v << 1, 2;	
	m.colwise() + v;
	m.rowwise() + v.transpose();
	
	// find the nearest
	Eigen::MatrixXi points(2, 10);
	points(0, Eigen::seq(0, 9)) = Eigen::ArrayXi::LinSpaced(10, 1, 10);
	points(1, Eigen::seq(9, 0, Eigen::fix<-1>)) = 
		Eigen::ArrayXi::LinSpaced(10, 1, 10);

	Eigen::VectorXi point(2);
	point << 0, 0;
			
	// the min distance
	(points.colwise() - point).colwise().squaredNorm().minCoeff();

	//
	

	std::cout << res << std::endl;
	return 0;
}
