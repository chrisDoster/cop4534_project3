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

int* BruteTS::findOptimalTour()
{
	int* optimalTour = nullptr;
	
	return optimalTour;
}

void BruteTS::heapsAlg(int arr[], int size, int n)
{
	/*int arr[size];
	for (int i=0; i < size; ++i)
	{
		arr[i] = mat[i];
	}*/
	
	if (size == 1)
	{
		std::cout << "PERMUTATION ADDED: ";
		for (int i=0; i < n; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		
		permutations.push_back(arr);
		return;
	}
	
	for (int i=0; i < size; ++i)
	{
		heapsAlg(arr, size-1, n);
		if ((size % 2) == 0)
		{
			swap(arr[i], arr[size-1]);
		}
		else
		{
			swap(arr[0], arr[size-1]);
		}
	}
}

std::vector<int*> BruteTS::getPermutations()
{
	return permutations;
}

