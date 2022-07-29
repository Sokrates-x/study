#include <iostream>
#include <vector>
#include <climits>
#include <functional>

static int count = 0;

int pick(std::vector<int> &w, std::vector<int> &v, std::vector<int> picked, 
	int W) {
	int max_v = 0;
	for (int i = 0; i < w.size(); ++i) {
		if (std::find(picked.cbegin(), picked.cend(), i) == picked.end()) {
			if (W >= w[i]) {
				std::vector<int> picked_i = picked;
				picked_i.push_back(i);
				int max_pick = pick(w, v, picked_i, W - w[i]);
				max_v = max_v > max_pick + v[i] ? max_v : max_pick + v[i];
				++count;
			}
		}
	}
	return max_v;
}
int main(int, char **) 
{
	// input
	std::vector<int> w { 3000, 534, 6341, 934124, 1100, 334342, 243242, 63424, 94234, 304324, 123242, 52311, 342141, 3452, 543251, 53452, 324, 35424, 234324,42354,43242,4234,432,4234,3242,45,2,5,451 };
	std::vector<int> v { 3000, 534, 6341, 934124, 1100, 334342, 243242, 63424, 94234, 304324, 123242, 52311, 342141, 3452, 543251, 53452, 324, 35424, 234324,42354,43242,4234,432,4234,3242,45,2,5,451 };
	int W = 5000;	

	// data
	std::cout << pick(w, v, std::vector<int>(), W) << std::endl;
	std::cout << count << std::endl;
	std::cout << w.size() << std::endl;
	return 0;
}
