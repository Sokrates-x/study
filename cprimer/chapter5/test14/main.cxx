#include <vector>
#include <set>
#include <iostream>

void countStr(const std::vector<std::string> &svec)
{
	std::string pre = *svec.cbegin();
	int n;
	for (auto m : svec)
	{
		++n;
		if (m == pre)
			continue;
		std::cout << pre << " Occurs " << --n << " times.\n"; 
		pre = m;
		n = 1;
	}
	std::cout << pre << " Occurs " << n << " times.\n"; 
	return;
}

void countStr_2(const std::vector<std::string> &svec)
{
	std::multiset<std::string> smset(svec.cbegin(), svec.cend());
	for (auto m = smset.begin(); m != smset.end(); m = smset.upper_bound(*m))
	{
		std::cout << *m << " Occurs " << smset.count(*m) << " times.\n";	
	}
	return;
}

int main(int argc, char **argv)
{
	std::vector<std::string> svec { "how", "now", "now", "now", "brown", 
		"cow", "cow" };
	countStr(svec);	
	countStr_2(svec);
	return 0;
}
