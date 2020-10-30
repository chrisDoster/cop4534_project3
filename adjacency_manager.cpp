#include "adjacency_manager.hpp"

AdjacencyManager::AdjacencyManager()
{
	
}

void AdjacencyManager::loadMatrix(double** newMat, int newMatSize)
{
	mat = newMat;
	matSize = newMatSize;
}

double AdjacencyManager::pathWeight(std::vector<int> path)
{
	double sum = 0.0;
	for (int i=0; i < path.size()-1; ++i)
	{
		sum += mat[path.at(i)][path.at(i+1)];
	}
	
	return sum;
}

