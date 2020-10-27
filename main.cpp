#include <iostream>
#include "genetic.hpp"
#include "brute.hpp"
#include "parser.hpp"

int main()
{
	BruteTS bTS;
	GeneticTS gTS;
	Parser p;
	double** adjMat = nullptr;
	adjMat = p.parseAdjacencies("distances.txt");
	
	int numCities = 0;
	int numToursPerGen = 0;
	int numGenerations = 0;
	double percentMutPerGen = 0;
	
	bTS.loadData(adjMat);
	gTS.loadData(adjMat);
	
	return 0;
}
