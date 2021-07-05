#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


class Array_Transformer {
public:
	virtual void Print() = 0;
	virtual void Sort() = 0;
	virtual int Get_len() = 0;
	virtual std::vector<int> Get_elem() = 0;

	virtual ~Array_Transformer() {};

};
class Array : public Array_Transformer {
private:
	std::vector<int> m_vec;
	int m_len{ 0 };

public:
	Array(std::vector<int> vec_int, int len) :m_vec(vec_int), m_len(len) {};
	~Array() { std::cout << ">>> Destruction of object." << std::endl; };

	void Print() {
		for (const auto& i : m_vec) {
			std::cout << i << " ";
		}
	};
	void Sort() { std::sort(m_vec.begin(), m_vec.end()); }
	int Get_len() { return m_len; }
	std::vector<int> Get_elem() { return m_vec; }

};