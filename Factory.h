#pragma once

#include <iostream>
#include <vector>


class Factory {
public:
	virtual Array_Transformer* Create_Array(std::vector<int> vec_int, int len) = 0;
	virtual ~Factory() {};
};

class Array_Factory : public Factory {
public:
	Array_Transformer* Create_Array(std::vector<int> vec_int, int len) {
		return new Array(vec_int, len);
	};
};