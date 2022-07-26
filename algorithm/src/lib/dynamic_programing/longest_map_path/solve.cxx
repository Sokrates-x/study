#include <iostream>
#include <climits>
#include <map>

int main(int, char **)
{
	 int G[5][5] = {
	 			{0, 1, 2, 3, 4},
	 			{INT_MIN, 0, 1, 2, 3},
	 			{INT_MIN, INT_MIN, 0, 1, 2},
	 			{INT_MIN, INT_MIN, INT_MIN, 0, 1},
	 			{INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0} };

	std::map<int, int[5][5]> map;
	std::map<int, bool[5][5]> bmap;

	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (k == 0) {
					map[k][i][j] = G[i][j];	
				} else {
					// Case 0: path don't through vertex i
					// Case 1: path through vertex i
					// path length = x->i->y because of no rings
					if (map[k - 1][i][k] != INT_MIN && map[k - 1][k][j] != INT_MIN) {
						map[k][i][j] = map[k - 1][i][k] + map[k - 1][k][j] > map[k - 1][i][j] ?
							map[k - 1][i][k] + map[k - 1][k][j] : map[k - 1][i][j];
						bmap[k][i][j] = map[k - 1][i][k] + map[k - 1][k][j] > map[k - 1][i][j] ?
							true : false;
					} else {
						map[k][i][j] = map[k - 1][i][j];
						bmap[k][i][j] = false;
					}
				}
				std::cout << map[k][i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "********************************************************************************\n";
	}
	return 0;
}
