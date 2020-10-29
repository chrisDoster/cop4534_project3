#include "brute.hpp"


void BruteTS::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


BruteTS::BruteTS()
{
	adjMat = nullptr;
	adjMatSize = -1;
}

void BruteTS::loadData(double** mat, int size)
{
	adjMat = mat;
	adjMatSize = size;
}

std::vector<int> BruteTS::findOptimalTour()
{
	std::vector<int> optimalTour;
	
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

