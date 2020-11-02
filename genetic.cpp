#include "genetic.hpp"

// testing functions
void printVector(std::vector<int> vec);
void printDoubleVector(std::vector<std::vector<int>>& vector2, AdjacencyManager& am);




void GeneticTS::swap(std::vector<int>& a, std::vector<int>& b)
{
	std::vector<int> temp = a;
	a = b;
	b = temp;
}
void GeneticTS::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void GeneticTS::permute(std::vector<int> arr)
{
	
}
int GeneticTS::factorial(int n)
{
	if (n==1)
		return n;
	else
		return n * factorial(n-1);
}
std::vector<int> GeneticTS::findMinPath()
{
	std::vector<int> minPath;
	if (!generation.empty())
	{
		minPath = generation.at(0);
		bool minIsFirst = true;
		int indexOfMin = -1;
		for (int i=1; i < generation.size(); ++i)
		{
			if (adjMat.pathWeight(generation.at(i)) < adjMat.pathWeight(minPath))
			{
				minPath = generation.at(i);
				minIsFirst = false;
				indexOfMin = i;
			}
		}
		if (minIsFirst)
		{
			swap(generation.at(0), generation.at(generation.size()-1));
			generation.pop_back();
		}
		else
		{
			swap(generation.at(indexOfMin), generation.at(generation.size()-1));
			generation.pop_back();
		}
	}
	return minPath;
}
void GeneticTS::prependAppendZero(std::vector<int>& tour)
{
	tour.insert(tour.begin(), 0);
	tour.push_back(0);
}



void GeneticTS::loadData(double** mat, int numCities, int numGenerations, int numToursPerGen, int percentMutPerGen)
{
	this->numCities = numCities;
	this->numGenerations = numGenerations;
	this->numToursPerGen = numToursPerGen;
	this->numElitesPerGen = 2;
	this->percentageMutations = percentMutPerGen;
	adjMat.loadMatrix(mat, numCities);
}
std::vector<int> GeneticTS::breedTours()
{
	std::vector<int> goodTour;
	
	// create initial tours randomly
	generation.clear();
	fillWithRandomTours(generation);
	
	/*std::cout << "first gen: \n";
	printDoubleVector(generation, adjMat);*/
	
	// test pathweights and select a number of elites
	std::vector<std::vector<int>> elites = findElites(generation);
	
	/*std::cout << "after elite removal: \n";
	printDoubleVector(generation, adjMat);
	
	std::cout << "elites: \n";
	printDoubleVector(elites, adjMat);*/
	
	// loop start
	// create new gen from elites, their mutations, and new random permutations
	for (int i=1; i < numGenerations; ++i)
	{
		generation.clear();
		addElites(generation, elites);
		addMutations(generation, elites);
		fillWithRandomTours(generation);
		elites = findElites(generation);
	}
	// test pathweights and choose new elites
	//loop end
	goodTour = elites.at(0);
	bestTour = goodTour;
	
	return goodTour;
}
double GeneticTS::getGoodWeight()
{
	return adjMat.pathWeight(bestTour);
}

void GeneticTS::addElites(std::vector<std::vector<int>> gen, std::vector<std::vector<int>> eliteList)
{
	for (int i=0; i < eliteList.size(); ++i)
	{
		gen.push_back(eliteList.at(i));
	}
}
void GeneticTS::addMutations(std::vector<std::vector<int>> gen, std::vector<std::vector<int>> eliteList)
{
	int numMut = numToursPerGen * percentageMutations / 100;
	std::random_device rd;
	for (int i=0; i < eliteList.size(); ++i)
	{
		std::vector<int> currElite = eliteList.at(i);
		for (int j=0; j < (numMut/eliteList.size()); ++j)
		{
			std::vector<int> mutation = currElite;
			int index1 = rd() % numCities;
			int index2 = rd() % numCities;
			swap(mutation.at(index1), mutation.at(index2));
			gen.push_back(mutation);
		}
	}
}
void GeneticTS::fillWithRandomTours(std::vector<std::vector<int>> gen)
{
	int maxNumberOfPermutations = factorial(numCities-1);
	std::vector<int> middle;
	for (int i=1; i < numCities; ++i)
	{	
		middle.push_back(i);
	}
	
	std::random_device rd;
	for (int i=0; i < numToursPerGen; ++i)
	{
		int rndmVal = rd() / maxNumberOfPermutations;
		for (int j=0; j < rndmVal; ++j)
		{
			next_permutation(middle.begin(), middle.end());
		}
		generation.push_back(middle);
	}
	for (int i=0; i < generation.size(); ++i)
	{
		prependAppendZero(generation.at(i));
	}
}
std::vector<std::vector<int>> GeneticTS::findElites(std::vector<std::vector<int>> gen)
{
	std::vector<std::vector<int>> elites;
	for (int i=0; i < numElitesPerGen; ++i)
	{
		std::vector<int> minPath = findMinPath();
		elites.push_back(minPath);
	}
	
	return elites;
}


// testing functions
void printVector(std::vector<int> vec)
{
	std::cout << "[ ";
	for (int i=0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << "] \n";
}
void printDoubleVector(std::vector<std::vector<int>>& vector2, AdjacencyManager& am)
{
	for (int i=0; i < vector2.size(); ++i)
	{
		std::cout << "[ ";
		for (int j=0; j < vector2.at(i).size(); ++j)
		{
			std::cout << vector2.at(i).at(j) << " ";
		}
		std::cout << "] ; weight = " << am.pathWeight(vector2.at(i)) << std::endl;
	}
}



