#pragma once

#include "Array_Transformer.h"
#include "Factory.h"

class Factory;
class Array_Transformer;

class Array_Factory;
class Array;

void Searching_two(Array_Transformer* max, Array_Transformer* min);
void Common_two(const std::vector<Array_Transformer*>& vec_arr_transf);

void Rsort(const std::vector<Array_Transformer*>& vec_arr_transf);
void Common_three(const std::vector<Array_Transformer*>& vec_arr_transf);
std::vector<std::vector<int>> readFile(std::istream& in);