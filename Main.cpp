// “естовое задание: ¬асиленко јнтон 

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <memory>

#include "All_function.h"

int main() {

	std::vector<std::vector<int>> vec_int;

	std::string file_name{ "C:/Users/Zoidberg724/Desktop/Given_array.txt" };
	std::ifstream in_file;
	
	in_file.open(file_name, std::ios_base::in);
	vec_int = readFile(in_file);

	//create each obj with new
	Array_Factory* vec_arr_factory1 = new Array_Factory;
	Array_Factory* vec_arr_factory2 = new Array_Factory;
	Array_Factory* vec_arr_factory3 = new Array_Factory;
		
	std::vector<Array_Transformer*> vec_arr_transf;
	vec_arr_transf.push_back(vec_arr_factory1->Create_Array(vec_int[0], vec_int[0].size()));
	vec_arr_transf.push_back(vec_arr_factory1->Create_Array(vec_int[1], vec_int[1].size()));
	vec_arr_transf.push_back(vec_arr_factory1->Create_Array(vec_int[2], vec_int[2].size()));

	// ------ Possible actions -----

	//Print
	std::cout << ">>> Printing object:" << std::endl;
	for (int i = 0; i < vec_arr_transf.size(); i++) {
		std::cout << "\t#" << i+1 << " :";
		vec_arr_transf[i]->Print();
		std::cout << "\n" << std::endl;
	}

	//Sort
	std::cout << ">>> Sorting object:" << std::endl;
	for (int i = 0; i < vec_arr_transf.size(); i++) {
		std::cout << "\t#" << i + 1 << " :";
		vec_arr_transf[i]->Sort();
		vec_arr_transf[i]->Print();
		std::cout << "\n" << std::endl;
	}

	//Common_two - пересечение  2-х и массивов (общие значени€)
	std::cout << ">>> Searching for common values in 2 longest object:" << std::endl;
	Common_two(vec_arr_transf);

	//Common_two - пересечение  3-х массивов (общие значени€)
	std::cout << ">>> Searching for common values in 3 object:" << std::endl;
	Common_three(vec_arr_transf);

	//RSort - обратный массив только из уникальных Їлементов
	std::cout << ">>> Searching unique values in 3 objects:" << std::endl;
	Rsort(vec_arr_transf);

	for (auto& it : vec_arr_transf) {
		delete it;
		it = nullptr;
	}

}