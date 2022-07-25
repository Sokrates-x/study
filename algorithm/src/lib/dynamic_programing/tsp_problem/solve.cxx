#include <map>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <functional>

// points
std::vector<int> vx { 0, 1, 2, 5, 6, 7, 8 };
std::vector<int> vy { 6, 0, 3, 4, 1, 5, 2 };

inline double len(int i, int j, std::vector<int> &vx = vx,
	std::vector<int> &vy = vy)
{
	return std::sqrt((vx[i] - vx[j])*(vx[i] - vx[j]) + (vy[i] - vy[j])*
		(vy[i] - vy[j]));
}

int main(int, char **)
{
	// min length of vi ended path
	std::map<int, std::map<int, double>> length;

	// min path for vj ended asuume j>=k
	// v0 -> vj
	std::map<int, std::map<int, std::vector<int>>> path;
	// v0 -> vk
	std::map<int, std::map<int ,std::vector<int>>> rpath;
	
	// v0->v1
	path[0][0].push_back(0);
	rpath[0][0].push_back(0);
	path[1][0].push_back(0);
	path[1][0].push_back(1);
	rpath[1][0].push_back(0);
	// v0->v0 no path
	length[1][0] = len(1, 0);	
	length[0][0] = len(0, 0);

	for (int j = 2; j <= vx.size(); ++j)
	{
		for (int k = 0; k < j; ++k){
			if (j > k + 1) //case: j>k+1
			{
				length[j][k] = length[j-1][k] + len(j-1, j);
				path[j][k] = path[j-1][k];
				path[j][k].push_back(j);
				rpath[j][k] = rpath[j-1][k];
			}
			if (j == k + 1) { //case: j=k+1 
				double m = INT_MAX;
				int ll = 0;
				for (int l = 0; l != j - 1; ++l)
					// l_k->l == l_l->k
					m > length[k][l] + len(l, j) ? m = length[k][l] + len(l,
						j), ll = l : m = m, ll = ll;
				length[j][k] = m;
				path[j][k] = rpath[k][ll];
				path[j][k].push_back(j);
				rpath[j][k] = path[k][ll];
			}
		}
	}

	length[6][6] = length[6][5] + len(6, 5);
	
	std::cout << length[6][6] << std::endl;
	std::copy(path[6][5].begin(), path[6][5].end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::copy(rpath[6][5].begin(), rpath[6][5].end(), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
