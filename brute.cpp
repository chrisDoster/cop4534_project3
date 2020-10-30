#include "brute.hpp"


void BruteTS::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


BruteTS::BruteTS()
{
	tourLength = 0;
}

void BruteTS::loadData(double** mat, int size)
{
	adjMat.loadMatrix(mat, size);
	tourLength = size;
}

std::vector<int> BruteTS::findOptimalTour()
{
	std::vector<int> optimalTour;
	
	// create vector of numbers [1, 2, 3, ..., n-1] representing the middle part of a tour that visits every destination in ascending order
	std::vector<int> middle;
	for (int i=1; i < tourLength; ++i)
	{
		middle.push_back(i);
	}
	permute(middle);
	// prepend and append a 0 to every permutation so that they represent a proper tour of cities
	for (int i=0; i < permutations.size(); ++i)
	{
		permutations.at(i).insert(permutations.at(i).begin(), 0);
		permutations.at(i).push_back(0);
	}
	
	optimalTour = permutations.at(0);
	std::cout << "perm = [ ";
	for (int i=0; i < permutations.at(0).size(); ++i)
		std::cout << permutations.at(0).at(i) << " ";
	std::cout << "] ; weight = " << adjMat.pathWeight(permutations.at(0)) << std::endl;
	for (int i=1; i < permutations.size(); ++i)
	{
		// print
		std::cout << "perm = [ ";
		for (int j=0; j < permutations.at(i).size(); ++j)
			std::cout << permutations.at(i).at(j) << " ";
		std::cout << "] ; weight = " << adjMat.pathWeight(permutations.at(i)) << std::endl;
		
		if (adjMat.pathWeight(permutations.at(i)) < adjMat.pathWeight(optimalTour))
		{
			optimalTour = permutations.at(i);
		}
	}
	
	return optimalTour;
}

void BruteTS::permute(std::vector<int>& mat)
{
	do
	{
		std::vector<int> arr = mat;
		permutations.push_back(arr);
	}
	while (next_permutation(mat.begin(), mat.end()));
}

void BruteTS::printPermutations(int sizeOfTour)
{
	std::cout << "PERMUTATIONS: \n";
	for (int i=0; i < permutations.size(); ++i)
	{
		for (int j=0; j < sizeOfTour; ++j)
		{
			std::cout << permutations.at(i)[j] << " ";
		}
		std::cout << std::endl;
	}
}

