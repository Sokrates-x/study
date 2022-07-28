#include <map>
#include <sstream>
#include <iostream>
#include <vector>

// the input paragraph
std::string str = "If a given line contains words i through j, where i<=j, and we leave exactly one space between words, the number of extra space characters at the end of the line is M - j + i, which must be nonnegative so that the words fit on the line. We wish to minimize the sum, over all lines except the last, of the cubes of the numbers of extra space characters at the ends of lines.";

int main(int, char **args)
{
	int M = std::stoi(std::string(*++args));
	// l_c_d[i][j] means i rows, j characters, and the best devision
	std::map<int, std::map<int, std::vector<int>>> l_c_d;
	// the neatness
	std::map<int, std::map<int, int>> neatness;

	std::istringstream is(str);
	std::string tmp;
	// len of string list
	int n = 0;
	// len of each string
	std::vector<int> len;
	std::vector<std::string> strv;
	while (is >> tmp) {
		len.push_back(tmp.size());
		strv.push_back(tmp);
		++n;
	}

	// row no.
	int rows = 1;		
	std::vector<int> rows_words;
	// left space
	int row_space_left = M;
	// row words no.
	int row_words = 0;

	for (int i = 0; i < n; ++i) {
		// space enough, row_space_left may be -1 but it dose not matter
		if (row_space_left >= len[i]) {
			++row_words;
			row_space_left -= len[i] + 1;
//			row_space_left = row_space_left >= 0 ? row_space_left : 0;
		} else {
		// space not enough for ith string, new row
			rows_words.push_back(row_words);
			row_space_left = M - len[i] - 1;	
			row_space_left = row_space_left >= 0 ? row_space_left : 0;
			row_words = 1;
			++rows;
		}
		// only one row
		if (rows == 1) {
			l_c_d[rows][i + 1] = std::vector<int>{i + 1};
			neatness[rows][i + 1] = (row_space_left + 1) * (row_space_left + 
								1) * (row_space_left + 1);
		} 
		if (rows > 1) {

			int shift = 0;
			int row_pre_words = i + 1 - row_words;
			int row_real_words = row_words;
			int row_real_left = row_space_left;
			int min_neat = (row_real_left + 1) * (row_real_left + 1) * 
						   (row_real_left + 1) + 
						   neatness[rows - 1][row_pre_words];

			// last rows - 1 row lcd lcd - 1...  lcd - shift words
			// this row may have 1...shift words
			while (row_real_left > len[row_pre_words - 1]) {
				// shift
				row_real_left -= len[row_pre_words - 1] + 1;
//				row_real_left = row_real_left >= 0 ? row_real_left : 0;
				--row_pre_words;
				++row_real_words;
				int tmp = (row_real_left + 1) * (row_real_left + 1) * 
					      (row_real_left + 1) + 
						  neatness[rows - 1][row_pre_words];
				if (tmp < min_neat) {
					min_neat = tmp;
					shift = row_real_words - row_words;
				}
			}
			
			// all shift compared
			neatness[rows][i + 1] = min_neat;	
			l_c_d[rows][i + 1] = l_c_d[rows - 1][i + 1 - row_words - shift];
			l_c_d[rows][i + 1].push_back(row_words + shift);
		}
	}

	int tot_words = 0;
	for (int i = 0; i < rows - 1; ++i)
		tot_words += rows_words[i];

	std::cout << neatness[rows - 1][tot_words] << std::endl;

	int j = 0, k = 0;
	for (int i = 0; i < strv.size(); ++i) {
		std::cout << strv[i] << " ";
		++j;
		if (j == l_c_d[rows - 1][tot_words][k]) {
			std::cout << '\n'; 
			++k;
			j = 0;
		}
	}

	std::cout << std::endl;
	
	return 0;
}
