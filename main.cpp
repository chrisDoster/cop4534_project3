#include "genetic.hpp"
#include "brute.hpp"
#include "parser.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void printMatrix(double** mat, int size);
void getInputsInteractively(int& numCities, int& numGenerations, int& numToursPerGen, int& percentMutPerGen);

int main()
{
	BruteTS bTS;
	GeneticTS gTS;
	Parser p;
	double** adjMat = nullptr;
	adjMat = p.parseAdjacencies("distances.txt");
	int x = p.getDimensionSize();
	//printMatrix(adjMat, x);
	
	int numCities;
	int numGenerations;
	int numToursPerGen;
	int percentMutPerGen;
	
	// get input interactively
	getInputsInteractively(numCities, numGenerations, numToursPerGen, percentMutPerGen);
	
	bTS.loadData(adjMat, numCities);
	gTS.loadData(adjMat, numCities, numGenerations, numToursPerGen, percentMutPerGen);
	
	
	std::vector<int> optimalTour = bTS.findOptimalTour();
	std::vector<int> goodTour = gTS.breedTours();
	
	//display results
	/*std::cout << "OPTIMAL: \n[ ";
	for (int i=0; i < optimalTour.size(); ++i)
		std::cout << optimalTour.at(i) << " ";
	std::cout << "] ; weight = " << bTS.getOptimalWeight() << std::endl;
	std::cout << "GOOD: \n[ ";
	for (int i=0; i < goodTour.size(); ++i)
		std::cout << goodTour.at(i) << " ";
	std::cout << "] ; weight = " << gTS.getGoodWeight() << std::endl;*/
	
	std::cout << "number of cities simulated: " << numCities << std::endl;
	std::cout << "optimal cost (found via brute force): " << bTS.getOptimalWeight() << std::endl;
	std::cout << "time taken by brute force algorithm: " << std::endl;
	std::cout << "approximated 'optimal' cost (found via genetic algorithm): " << gTS.getGoodWeight() << std::endl;
	std::cout << "time taken by genetic algorithm: " << std::endl;
	std::cout << "percent of optimal cost found by genetic algorithm: " << (int) (gTS.getGoodWeight() / bTS.getOptimalWeight() * 100) << std::endl;
	
	for (int i=0; i < x; ++i)
	{
		delete [] adjMat[i];
	}
	delete [] adjMat;
	
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
void getInputsInteractively(int& numCities, int& numGenerations, int& numToursPerGen, int& percentMutPerGen)
{
	bool invalidInput = true;
	while (invalidInput)
	{
		std::cout << "Enter the number of cities to simulate (an integer within range [1, 20]): \n";
		std::string line = "";
		std::getline(std::cin, line);
		int lineInt;
		try
		{
			lineInt = stoi(line);
		}
		catch (std::exception e)
		{
			std::cout << "ERROR: invalid data type! please only enter integer values \n";
		}
		
		if (lineInt <= 20 && lineInt >= 1)
		{
			numCities = lineInt;
			invalidInput = false;
		}
	}
	invalidInput = true;
	while (invalidInput)
	{
		std::cout << "Enter the number of generations to simulate (a positive integer): \n";
		std::string line = "";
		std::getline(std::cin, line);
		int lineInt;
		try
		{
			lineInt = stoi(line);
		}
		catch (std::exception e)
		{
			std::cout << "ERROR: invalid data type! please only enter integer values \n";
		}
		
		if (lineInt > 0)
		{
			numGenerations = lineInt;
			invalidInput = false;
		}
	}
	invalidInput = true;
	while (invalidInput)
	{
		std::cout << "Enter the number of tours to simulate per generation (an integer >= 2): \n";
		std::string line = "";
		std::getline(std::cin, line);
		int lineInt;
		try
		{
			lineInt = stoi(line);
		}
		catch (std::exception e)
		{
			std::cout << "ERROR: invalid data type! please only enter integer values \n";
		}
		
		if (lineInt >= 2)
		{
			numToursPerGen = lineInt;
			invalidInput = false;
		}
	}
	invalidInput = true;
	while (invalidInput)
	{
		std::cout << "Enter the percentage of a generation that should be comprised of mutations (an integer within range [0, 100]): \n";
		std::string line = "";
		std::getline(std::cin, line);
		int lineInt;
		try
		{
			lineInt = stoi(line);
		}
		catch (std::exception e)
		{
			std::cout << "ERROR: invalid data type! please only enter integer values \n";
		}
		
		if (lineInt <= 100 && lineInt >= 0)
		{
			percentMutPerGen = lineInt;
			invalidInput = false;
		}
	}
}


