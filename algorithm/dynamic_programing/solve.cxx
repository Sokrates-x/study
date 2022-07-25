#include <iostream>
#include <climits>

int main(int argc, char **)
{
	// m x n Input
	int (*p)[8] = new int[8][8] {
				{ 3, 2, 5, 6, 1, 9, 7, 2 },
				{ 2, 3, 4, 5, 1, 5, 4, 9 },
				{ 6, 3, 4, 1, 3, 2, 4, 6 },
				{ 9, 1, 4, 6, 5, 1, 7, 3 },
				{ 3, 5, 4, 5, 6, 0, 8, 5 },	
				{ 5, 4, 7, 9, 8, 4, 5, 6 },
				{ 4, 8, 9, 6, 0, 3, 7, 4 },
				{ 5, 1, 6, 4, 7, 5, 6, 2 } };

	char flag[8][8];

	for (int i = 0; i != 8; ++i) {
		for (int j = 0; j != 8; ++j) {
			if (i > 0) {
				if (j == 0)	{
					p[i][j] += p[i - 1][j + 1] > p[i - 1][j] ? p[i - 1][j] : p[i - 1][j + 1];
					flag[i][j] = p[i - 1][j + 1] > p[i - 1][j] ? 'm' : 'r';
				} else if (j == 7) {
					p[i][j] += p[i - 1][j - 1] > p[i - 1][j] ? p[i - 1][j] : p[i - 1][j - 1];
					flag[i][j] = p[i - 1][j - 1] > p[i - 1][j] ? 'm' : 'l';
				} else {
					p[i][j] += p[i - 1][j - 1] > p[i - 1][j] ? 
								p[i - 1][j] > p[i - 1][j + 1] ? p[i - 1][j + 1] : p[i - 1][j] :
								p[i - 1][j - 1] > p[i - 1][j + 1] ? p[i - 1][j + 1] : p[i - 1][j - 1];
					flag[i][j] = p[i - 1][j - 1] > p[i - 1][j] ? 
								  p[i - 1][j] > p[i - 1][j + 1] ? 'r' : 'm' :
								  p[i - 1][j - 1] > p[i - 1][j + 1] ? 'r' : 'l';
				}
			} else {
				flag[i][j] = 'p';
			}
		}
	}
	int m = INT_MAX;
	int posy = 7, posx;
	for (int i = 0; i != 8; ++i) {
		posx = m > p[7][i] ? i : posx;
		m = m > p[7][i] ? p[7][i] : m;
	}
	std::cout << "MIN Total Cost: " << m << std::endl;
	std::cout << "MIN Cost Path: " << std::endl;
	char c = flag[posy][posx];
	std::cout << "(" << posx << ", " << posy << ")\n";
	while (c != 'p') {
		switch (c)	
		{
		case 'l':
			std::cout << "(" << --posx << ", " << --posy << ")\n";
			c = flag[posy][posx];
			break;
		case 'm':
			std::cout << "(" << posx << ", " << --posy << ")\n";
			c = flag[posy][posx];
			break;
		case 'r':
			std::cout << "(" << ++posx << ", " << --posy << ")\n";
			c = flag[posy][posx];
			break;
		default:;
		}
	}

	return 0;
}
