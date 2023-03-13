#include <iostream>
#include "../include/vector.hpp"





int main()
{
	base::Vector<int, 5> vec_a = { 1, 2, 3 , 1, 10};
	base::Vector<int, 5> vec_b = { 4, 5, 6 , 7, 8};



	//base::Vector<int, 5> vec_c = vec_a + vec_b;
	//base::Vector<int, 5> vec_c = vec_a.dot(vec_b);
	int vec_c = vec_a * vec_b;
	std::cout << vec_c << std::endl;

	std::cin.get();
}