#include <vector>
#include <iostream>
#include <map>

int main(int, char **)
{
	std::vector<char> A{ 'A', 'B', 'C', 'B', 'D', 'A', 'B' };
	std::vector<char> B{ 'B', 'D', 'C', 'A', 'B', 'A' };

	std::map<int, std::map<int, std::pair<int, std::pair<int, int>>>> m;
	for (int j = 1; j <= A.size(); ++j)
		m[j][0] = std::make_pair(0, std::make_pair(j, 0));
	
	for (int k = 1; k <= B.size(); ++k)
		m[0][k] = std::make_pair(0, std::make_pair(0, k));

	for (int i = 1; i <= (A.size() > B.size() ? B.size() : A.size()); ++i)
	{
		// j = i->Asz, k = i
		for (int j = i; j <= A.size(); ++j)
		{
			// Aj = Ak
			if (A[j-1] == B[i-1])
			{
				m[j][i] = std::make_pair(m[j-1][i-1].first + 1,
					std::make_pair(j, i));
			}
			// Aj != Ak
			else
			{
				m[j][i] = m[j-1][i].first > m[j][i-1].first ? m[j-1][i] :
					m[j][i-1];
			}
		}
		// k = i->Bsz, j = i
		for (int k = i + 1; k <= B.size(); ++k)
		{
			// Aj = Ak
			if (A[i-1] == B[k-1])	
			{
				m[i][k] = std::make_pair(m[i-1][k-1].first + 1,
					std::make_pair(i, k));
			}
			// Aj != Ak
			else
			{
				m[i][k] = m[i-1][k].first > m[i][k-1].first ? m[i-1][k] :
					m[i][k-1];
			}
		}
	}
	
	int i = 7, j = 6;
	std::cout << "LCS Length: " <<  m[i][j].first << std::endl;
	std::cout << "LCS is: ";
	while (m[i][j].first >= 1)
	{
		auto tmp = m[i][j].second;
		std::cout << A[tmp.first-1] << " ";
		i = tmp.first - 1;
		j = tmp.second - 1; 
	}
	std::cout << std::endl;
	return 0;
}
