#ifndef BRUTE_HPP
#define BRUTE_HPP

#include <iostream>
#include <vector>

class BruteTS
{
	private:
		std::vector<int*> permutations;
		double** adjMat;
		int adjMatSize;
		void swap(int& a, int&b);
		
	public:
		BruteTS();
		void loadData(double** mat, int size);
		int* findOptimalTour();
		void heapsAlg(int arr[], int size, int n);
		std::vector<int*> getPermutations();
		
};



#endif