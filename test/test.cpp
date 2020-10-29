#define CATCH_CONFIG_MAIN

#include <sstream>
#include <iostream>
#include <algorithm>
#include "catch/catch.hpp"
#include "../brute.hpp"

std::string matToStr(std::vector<int> mat, int size)
{
	std::ostringstream ss;
	ss << "Adjacency Matrix: \n[ ";
	for (int i=0; i < size; ++i)
	{
		ss << mat.at(i) << " ";
	}
	ss << "] \n";
	return ss.str();
}


TEST_CASE("Heap's Algorithm")
{
	std::vector<int> mat;
	for (int i=0; i < 4; ++i)
	{
		mat.push_back(i);
	}
	std::string beforeHeaps = matToStr(mat, 4);
	REQUIRE ("Adjacency Matrix: \n[ 0 1 2 3 ] \n" == beforeHeaps);
	
	BruteTS b;
	b.permute(mat);
	
	b.printPermutations(4);
}
