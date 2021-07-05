#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "All_function.h"

void Rsort(const std::vector<Array_Transformer*>& vec_arr_transf) {

	std::vector<int> vec_res(vec_arr_transf.size());
	std::vector<int> tmp;
	int base_count{ 0 };

	for (int i = 0; i < vec_arr_transf.size(); i++) {
		for (int j = 0; j < vec_arr_transf[i]->Get_len(); j++) {
			base_count++;
		}
	}

	for (int i = 0; i < vec_arr_transf.size(); i++) {
		tmp = vec_arr_transf[i]->Get_elem();
		for (int j = 0; j < tmp.size(); j++) {
			vec_res.push_back(tmp[j]);
		}
	}

	std::sort(vec_res.begin(), vec_res.end());
	std::vector<int>::iterator it;
	it = std::unique(vec_res.begin(), vec_res.end());
	vec_res.resize(it - vec_res.begin());

	std::sort(vec_res.begin(), vec_res.end(), std::greater<int>());


	std::cout << "\t--- All 3 arrays contains [" << base_count << "] values. Rsort() redused it to [" << vec_res.size() << "] values ---" << std::endl;

	std::cout << "\t";
	for (const auto& i : vec_res) {
		std::cout << i << " ";
	}
	std::cout << "\n" << std::endl;

}

void Common_three(const std::vector<Array_Transformer*>& vec_arr_transf) {
	std::vector<int> vec_one;
	std::vector<int> vec_two;
	std::vector<int> vec_three;

	std::vector<int> vec_tmp;

	vec_one = vec_arr_transf[0]->Get_elem();
	vec_two = vec_arr_transf[1]->Get_elem();
	vec_three = vec_arr_transf[2]->Get_elem();

	std::vector<int> vec_res;

	std::sort(vec_one.begin(), vec_one.end());
	std::sort(vec_two.begin(), vec_two.end());
	std::sort(vec_three.begin(), vec_three.end());

	std::set_intersection(vec_one.begin(), vec_one.end(), vec_two.begin(), vec_two.end(), std::back_inserter(vec_tmp));
	std::set_intersection(vec_tmp.begin(), vec_tmp.end(), vec_three.begin(), vec_three.end(), std::back_inserter(vec_res));

	if (vec_res.empty()) {
		std::cout << ">>> ERROR: there are no common values in 2 longest arrays!" << std::endl;
	}
	else {
		std::cout << "\t";
		for (const auto& i : vec_res) {
			std::cout << i << " ";
		}
		std::cout << "\n" << std::endl;
	}
}

void Searching_two(Array_Transformer* max, Array_Transformer* min) {
	std::vector<int> vec_res;
	std::vector<int> vec_max;
	std::vector<int> vec_min;

	vec_max = max->Get_elem();
	vec_min = min->Get_elem();

	std::sort(vec_max.begin(), vec_max.end());
	std::sort(vec_min.begin(), vec_min.end());

	std::set_intersection(vec_max.begin(), vec_max.end(),
		vec_min.begin(), vec_min.end(),
		std::back_inserter(vec_res));
	if (vec_res.empty()) {
		std::cout << ">>> ERROR: there are no common values in 2 longest arrays!" << std::endl;
	}
	else {
		std::cout << "\t";
		for (const auto& i : vec_res) {
			std::cout << i << " ";
		}
		std::cout << "\n" << std::endl;
	}
}
void Common_two(const std::vector<Array_Transformer*>& vec_arr_transf) {

	if (vec_arr_transf[0]->Get_len() == vec_arr_transf[1]->Get_len() && vec_arr_transf[1]->Get_len() == vec_arr_transf[2]->Get_len()) {
		std::cout << ">>> ERROR: all 3 arrays have equal length. Impossible to determine 2 of them !" << std::endl;
	}
	else if (vec_arr_transf[0]->Get_len() > vec_arr_transf[1]->Get_len() && vec_arr_transf[0]->Get_len() > vec_arr_transf[2]->Get_len()) {

		if (vec_arr_transf[1]->Get_len() == vec_arr_transf[2]->Get_len())
			std::cout << "ERROR: Impossible to determine 2nd longest array!" << std::endl;
		else if (vec_arr_transf[1]->Get_len() > vec_arr_transf[2]->Get_len() || vec_arr_transf[0]->Get_len() == vec_arr_transf[1]->Get_len())
			Searching_two(vec_arr_transf[0], vec_arr_transf[1]);
		else
			Searching_two(vec_arr_transf[0], vec_arr_transf[2]);
	}
	else if (vec_arr_transf[1]->Get_len() > vec_arr_transf[0]->Get_len() && vec_arr_transf[1]->Get_len() > vec_arr_transf[2]->Get_len()) {
		if (vec_arr_transf[0]->Get_len() == vec_arr_transf[2]->Get_len())
			std::cout << "ERROR: Impossible to determine 2nd longest array!" << std::endl;
		else if (vec_arr_transf[0]->Get_len() > vec_arr_transf[2]->Get_len() || vec_arr_transf[1]->Get_len() == vec_arr_transf[0]->Get_len())
			Searching_two(vec_arr_transf[1], vec_arr_transf[0]);
		else
			Searching_two(vec_arr_transf[1], vec_arr_transf[2]);
	}
	else if (vec_arr_transf[2]->Get_len() > vec_arr_transf[0]->Get_len() && vec_arr_transf[2]->Get_len() > vec_arr_transf[1]->Get_len()) {
		if (vec_arr_transf[0]->Get_len() == vec_arr_transf[1]->Get_len())
			std::cout << "ERROR: Impossible to determine 2nd longest array!" << std::endl;
		else if (vec_arr_transf[0]->Get_len() > vec_arr_transf[1]->Get_len() || vec_arr_transf[2]->Get_len() == vec_arr_transf[0]->Get_len())
			Searching_two(vec_arr_transf[2], vec_arr_transf[0]);
		else
			Searching_two(vec_arr_transf[2], vec_arr_transf[1]);
	}
}

std::vector<std::vector<int>> readFile(std::istream& in)
{
	std::vector<std::vector<int>> result_vec;
	std::string buf;
	int count{ 0 };

	std::cout << ">>> Searching for specific file..." << std::endl;

	while (getline(in, buf))
	{
		replace(buf.begin(), buf.end(), ',', ' ');  // Заменяем запятые пробелами
		std::istringstream is(buf);
		std::vector<int> tmp_vec;
		// Читаем новый вектор
		copy(std::istream_iterator<int>(is), std::istream_iterator<int>(),
			back_inserter(tmp_vec));
		// вставляем в коллекцию
		result_vec.push_back(tmp_vec);
		count++;
	}
	if (in.eof()) {
		std::cout << ">>> End of file reached." << std::endl;
	}
	else if (in.fail()) {
		std::cout << ">>> ERROR: input terminated by data mismatch." << std::endl;
		std::cout << "\t--- Make sure the path to the given file is correct ---" << std::endl;
		exit(1);
	}
	else {
		std::cout << ">>> ERROR: input terminated for uknown reason." << std::endl;
		exit(1);
	}

	if (count == 0) {
		std::cout << ">>> ERROR: no data processed." << std::endl;
	}
	else {
		std::cout << ">>> Data recieved.\n" << std::endl;
	}

	return result_vec;
}