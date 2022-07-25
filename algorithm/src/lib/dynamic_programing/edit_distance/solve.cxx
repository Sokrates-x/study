#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <iterator>
#include <functional>

int main(int, char **)
{
	std::vector<char> X { 'G', 'A', 'T', 'C', 'G', 'G', 'C', 'A', 'T' };	
	std::vector<char> Y { 'C', 'A', 'A', 'T', 'G', 'T', 'G', 'A', 'A', 'T', 
		'C' };

	int copy = 0, replace = 1, swap = 4, insert = 3, del = 2, teminate = 5;

	std::map<int, std::map<int, int>> cost;
	std::map<int, std::map<int, std::vector<char>>> operation;

	bool teminated = false;
	for (int i = 0; i <= X.size(); ++i) {
		for (int j = 0; j <= Y.size(); ++j) {
			if (i == 0 && j == 0)
			{
				cost[i][j] = 0;
				operation[i][j] = std::vector<char>();
				continue;
			}
			// edited string has been used completely
			if (i == 0 && j != 0) {
				// i exceed ranges
				// only insert aviliable
				cost[i][j] = cost[i][j - 1] + insert;
				operation[i][j] = operation[i][j - 1];
				operation[i][j].push_back('i');
				continue;
			}
			// editing string has been eidted 
			if (j == 0 && i != 0) {
				// remove last or teminate
				if (teminated) {
					cost[i][j] = cost[i - 1][j];
					operation[i][j] = operation[i - 1][j];
					continue;
				}
				if (del*i > teminate) {
					// teminate
					cost[i][j] = teminate;
					operation[i][j] = std::vector<char>{'t'};
					teminated = true;
				} else {
					// just choose normal delete
					cost[i][j] = cost[i - 1][j] + del;
					operation[i][j] = operation[i - 1][j];
					operation[i][j].push_back('d');
				}
				continue;
			 }

			//- Normal Case 
			int c = INT_MAX;
			char flag;
			// case copy
			if (X[i - 1] == Y[j - 1])
				c > cost[i - 1][j - 1] + copy ? flag = 'c', c = 
					cost[i - 1][j - 1] + copy : c = c;
			// case replace
			c > cost[i - 1][j - 1] + replace ? flag = 'r', c = 
				cost[i - 1][j - 1] + replace : c = c;
			// case insert
			c > cost[i][j - 1] + insert ? flag = 'i', c = cost[i][j - 1] + 
				insert : c = c;
			// case delete
			c > cost[i - 1][j] + del ? flag = 'd', c = cost[i - 1][j] + 
				del : c = c;
			// case swap
			if (i >= 2 && j >= 2 && X[i - 2] == Y[j - 1] && X[i - 1] 
				== Y[j - 2])
				c > cost[i - 2][j - 2] + swap ? flag = 's', c = 
					cost[i - 2][j - 2] + swap : c = c;

			cost[i][j] = c;	
			// choose operation
			switch(flag) {
			case 'c':
				operation[i][j] = operation[i - 1][j - 1];			
				operation[i][j].push_back('c');
				break;
			case 'r':
				operation[i][j] = operation[i - 1][j - 1];			
				operation[i][j].push_back('r');			
				break;
			case 'i':
				operation[i][j] = operation[i][j - 1];
				operation[i][j].push_back('i');			
				break;
			case 'd':
				operation[i][j] = operation[i - 1][j];			
				operation[i][j].push_back('d');			
				break;
			case 's':
				operation[i][j] = operation[i - 2][j - 2];			
				operation[i][j].push_back('s');			
				break;
			default:
				std::cerr << "Operation NOT Found" << std::endl;
				break;
			}
		}
	}

	std::cout << "Total Cost: " << cost[X.size()][Y.size()] << '\n';
	std::cout << "X Serials: \n";
	std::copy (X.cbegin(), X.cend(), std::ostream_iterator<char>(
		std::cout, " "));
	std::cout << "\nY Serials: \n";
	std::copy (Y.cbegin(), Y.cend(), std::ostream_iterator<char>(
		std::cout, " "));
	std::cout << "\nOperation Serials: \n";
	std::copy (operation[X.size()][Y.size()].cbegin(), 
		operation[X.size()][Y.size()].cend(), std::ostream_iterator<char>(
		std::cout, " "));
	std::cout << std::endl;

	return 0;
}
