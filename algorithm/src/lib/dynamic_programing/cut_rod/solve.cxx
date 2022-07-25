#include <iostream>
#include <string>
#include <map>

int main(int, char **argv)
{
	std::map<int, int> lp_map;
	lp_map[1] = 1;	
	lp_map[2] = 5;	
	lp_map[3] = 8;	
	lp_map[4] = 9;	
	lp_map[5] = 10;	
	lp_map[6] = 17;	
	lp_map[7] = 17;	
	lp_map[8] = 20;	
	lp_map[9] =	24;	
	lp_map[10] = 30;	

	// total length
	int n = std::stoi(std::string(*++argv));

	// max price for length=n
	int max_price[n + 1];
	for (auto &m : max_price) m = 0;

	// first cut for max price of length n
	int cut[n + 1];
	for (auto &m : cut) m = 0;

	// length 1 price
	max_price[1] = lp_map[1];	

	// length 1 cut
	cut[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		// max price for length = i
		for (int j = 1; j < i; ++j)
		{
			if (max_price[j] + max_price[i - j] > max_price[i])	
			{
				max_price[i] = max_price[j] + max_price[i - j];
				cut[i] = j;	
			}
		}
		if (i <= lp_map.size() && max_price[i] < lp_map[i])
		{
			max_price[i] = lp_map[i];
			cut[i] = i;
		}
	}
	std::cout << "Total_price: " << max_price[n] << std::endl;
	std::cout << "Max Cut: ";

	while (n > 0)
	{
		std::cout << cut[n] << " ";
		n -= cut[n];
	}
	std::cout << std::endl;

	return 0;
}
