#include <iostream>
#include <vector>

int main(int, char **)
{

// input
std::vector<int> w { 0, 3000, 534, 6341, 934124, 1100, 334342, 243242, 63424, 94234, 304324, 123242, 52311, 342141, 3452, 543251, 53452, 324, 35424, 234324,42354,43242,4234,432,4234,3242,45,2,5,451 };
std::vector<int> v { 0, 3000, 534, 6341, 934124, 1100, 334342, 243242, 63424, 94234, 304324, 123242, 52311, 342141, 3452, 543251, 53452, 324, 35424, 234324,42354,43242,4234,432,4234,3242,45,2,5,451 };
int W = 20002;

	int table[w.size()][W + 1];
	for (int i = 0; i < W + 1; ++i)
		table[0][i] = 0;

	for (int i = 1; i < w.size(); ++i) {
		for (int j = 0; j <= W; ++j) {
			if (j >= w[i]) {
				table[i][j]	= table[i - 1][j] > table[i - 1][j - w[i]] + 
								v[i] ? table[i - 1][j] : 
								table[i - 1][j - w[i]] + v[i];
			} else {
				table[i][j] = table[i - 1][j];
			}
		}
	}
	
	std::cout << table[23][W] << std::endl;
	return 0;
}
