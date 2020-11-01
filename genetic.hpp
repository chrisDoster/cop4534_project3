#ifndef GENETIC_HPP
#define GENETIC_HPP

#include "adjacency_manager.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class GeneticTS
{
	private:
		std::vector<int> bestTour;
		std::vector<std::vector<int>> generation;
		int numCities;
		int numGenerations;
		int numToursPerGen;
		int percentageMutations;
		int numElitesPerGen;
		AdjacencyManager adjMat;
		
		void addElites(std::vector<std::vector<int>> gen, std::vector<std::vector<int>> eliteList);
		void addMutations(std::vector<std::vector<int>> gen, std::vector<std::vector<int>> eliteList);
		void fillWithRandomTours(std::vector<std::vector<int>> gen);
		std::vector<std::vector<int>> findElites(std::vector<std::vector<int>> gen);
		
		void swap(std::vector<int>& a, std::vector<int>& b);
		void swap(int& a, int& b);
		void permute(std::vector<int> arr);
		int factorial(int n);
		std::vector<int> findMinPath();
		void prependAppendZero(std::vector<int>& tour);
		
	public:
		void loadData(double** mat, int numCities, int numGenerations, int numToursPerGen, int percentMutPerGen);
		std::vector<int> breedTours();
		double getGoodWeight();
};



#endif