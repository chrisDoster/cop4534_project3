#ifndef BRUTE_HPP
#define BRUTE_HPP

#include "adjacency_manager.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class BruteTS
{
	private:
		std::vector<int> bestTour;
		int tourLength;
		std::vector<std::vector<int>> permutations;
		AdjacencyManager adjMat;
		
		void swap(int& a, int& b);
		
	public:
		BruteTS();
		void loadData(double** mat, int size);
		std::vector<int> findOptimalTour();
		void permute(std::vector<int>& mat);
		void printPermutations(int sizeOfTour);
		double getOptimalWeight();
		
};



#endif