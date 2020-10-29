#ifndef BRUTE_HPP
#define BRUTE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class BruteTS
{
	private:
		std::vector<std::vector<int>> permutations;
		double** adjMat;
		int adjMatSize;
		void swap(int& a, int& b);
		
	public:
		BruteTS();
		void loadData(double** mat, int size);
		std::vector<int> findOptimalTour();
		void permute(std::vector<int>& mat);
		void printPermutations(int sizeOfTour);
		
};



#endif