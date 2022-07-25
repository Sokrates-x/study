#include <iostream>
#include <climits>
#include <map>

void print(int i, int j, std::map<int, std::map<int, int>> r)
{
	if (i < 1 || i >= j || j > 5)
		return;	
	int root = r[i][j];
	std::cout << i << "->" << root << "<-" << j << '\n';
	print(i, root - 1, r);
	print(root + 1, j, r);
}

int main(int, char **)
{
	std::map<int, double> major; 	
	major[1] = 0.15;
	major[2] = 0.10;
	major[3] = 0.05;
	major[4] = 0.10;
	major[5] = 0.20;
	std::map<int, double> minor;
	minor[0] = 0.05;
	minor[1] = 0.10;
	minor[2] = 0.05;
	minor[3] = 0.05;
	minor[4] = 0.05;
	minor[5] = 0.10;

	std::map<int, std::map<int, double>> cost;
	std::map<int, std::map<int, int>> root;
	std::map<int, std::map<int, double>> ncost;

	// begin
	int n = 5;

	// ncost for 1 major
	for (int i = 1; i <= n; ++i)
		ncost[i][i] = minor[i-1] + minor[i] + major[i];
	
	// size 0 problem there exists only one minor node
	for (int i = 1; i <= n; ++i)
	{
		// j->j+i-1 major nodes
		for (int j = 1; j + i - 1 <= n; ++j)
		{
			cost[j][j+i-1] = 10000.0f;
			// choose root node k
			for (int k = j; k <= j + i -1; ++k)
			{
				// j->k-1 & k & k+1->j+i-1
				double m = 0.f; // temp cost
				// left subtree possiblly no major left
				m += k==j ? minor[k-1] + minor[k-1]: cost[j][k-1] + 
					ncost[j][k-1]; 
				// right subtree possiblly no major right
				m += k==j+i-1 ? minor[k] + minor[k] : cost[k+1][j+i-1] +
					ncost[k+1][j+i-1];
				// root k
				m += major[k];

				if (m < cost[j][j+i-1])
				{
					cost[j][j+i-1] = m;
					root[j][j+i-1] = k;
				}
			}
			// ncost update
			if (i >= 2)	
				ncost[j][j+i-1] = ncost[j][j] + ncost[j+1][j+i-1] - minor[j];
		}
	}

	std::cout << "Total Cost: " << cost[1][5] << std::endl;
	std::cout << "Roots: " << std::endl;
	print(1, 5, root);

	return 0;
}
