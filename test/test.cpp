#define CATCH_CONFIG_MAIN

#include <sstream>
#include <iostream>
#include <algorithm>
#include "catch/catch.hpp"
#include "../brute.hpp"

std::string matToStr(int* mat, int size)
{
	std::ostringstream ss;
	ss << "Adjacency Matrix: \n[ ";
	for (int i=0; i < size; ++i)
	{
		ss << mat[i] << " ";
	}
	ss << "] \n";
	return ss.str();
}


TEST_CASE("Heap's Algorithm")
{
	int* mat = new int[4];
	for (int i=0; i < 4; ++i)
	{
		mat[i] = i;
	}
	std::string beforeHeaps = matToStr(mat, 4);
	REQUIRE ("Adjacency Matrix: \n[ 0 1 2 3 ] \n" == beforeHeaps);
	
	BruteTS b;
	b.heapsAlg(mat, 4, 4);
	
	std::vector<int*> perms = b.getPermutations();
	
	std::cout << "PERMUTATIONS: \n";
	for (int i=0; i < perms.size(); ++i)
	{
		for (int j=0; j < 4; ++j)
		{
			std::cout << perms.at(i)[j] << " ";
		}
		std::cout << std::endl;
	}
}
