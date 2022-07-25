#include <vector>
#include <map>
#include <climits>
#include <iostream>

struct M{
	int r;
	int c;
};

void print(int i, int j, std::map<int, std::map<int, std::pair<int, int>>> m)
{
	if (m[i][j].second == 0)
		return;
	std::cout << m[i][j].second << " ";	
	print(i, m[i][j].second, m);
	print(m[i][j].second + 1, j, m);
}

int main()
{
	M m1, m2, m3, m4, m5, m6;
	m1.c = 30;
	m1.r = 35;
	m2.c = 35;
	m2.r = 15;
	m3.c = 15;
	m3.r = 5;
	m4.c = 5;
	m4.r = 10;
	m5.c = 10;
	m5.r = 20;
	m6.c = 20;
	m6.r = 25;

	std::vector<M> v { m1, m2, m3, m4, m5, m6 };

	int n = 6;	
	std::map<int, std::map<int, std::pair<int, int>>> m;

	// one matrix mutiple 1-1 .... 6-6
	for (int i = 0; i != n; ++i)
	{
		m[i + 1][i + 1] = std::make_pair(0, 0);
	}

	for (int i = 2; i <= n; ++i)
	{
		// j->j+i-1, j+1->j+i-1, ...->n
		for (int j = 1; j + i - 1 <= n; ++j)
		{
			// j->j+i-1
			int min = INT_MAX;
			for (int k = j; k + 1 < j + i; ++k)
			{
				// j->k & k+1->j+i-1; 
				int temp = m[j][k].first + m[k + 1][j + i - 1].first
							+ v[j - 1].c * v[k - 1].r * v[j + i - 2].r;
				if (temp < min)
				{
					min = temp;
					m[j][j + i - 1] = std::make_pair(temp, k); 
				}
			}
		}
	}
	
	std::cout << "Total mutiplies: ";
	std::cout << m[1][6].first << std::endl;
	std::cout << "Seperated at: ";
	print(1, 6, m);
	std::cout << std::endl;
	return 0;
}
