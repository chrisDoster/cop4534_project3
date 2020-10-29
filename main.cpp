#include <iostream>
#include <iomanip>
#include "genetic.hpp"
#include "brute.hpp"
#include "parser.hpp"

void printMatrix(double** mat, int size);

int main()
{
	BruteTS bTS;
	GeneticTS gTS;
	Parser p;
	double** adjMat = nullptr;
	adjMat = p.parseAdjacencies("distances.txt");
	int x = p.getDimensionSize();
	printMatrix(adjMat, x);
	
	int numCities = 0;
	int numToursPerGen = 0;
	int numGenerations = 0;
	double percentMutPerGen = 0;
	
	bTS.loadData(adjMat, numCities);
	gTS.loadData(adjMat);
	
	int* optimalTour = bTS.findOptimalTour();
	int* goodTour = gTS.breedTours();
	
	return 0;
}

// pretty print function for testing
void printMatrix(double** mat, int size)
{
	std::cout << "Adjacency Matrix: \n";
	for (int i=0; i < size; ++i)
	{
		std::cout << "[ ";
		for (int j=0; j < size; ++j)
		{
			int absValMat = abs((int) mat[i][j]);
			if (absValMat == 0)
				std::cout << std::setprecision(4) << std::fixed;
			if (absValMat >= 10)
				std::cout << std::setprecision(3) << std::fixed;
			if (absValMat >= 100)
				std::cout << std::setprecision(2) << std::fixed;
			std::cout << mat[i][j] << "  ";
		}
		std::cout << "] \n";
	}
}

