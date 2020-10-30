#ifndef ADJACENCY_MANAGER
#define ADJACENCY_MANAGER

#include <vector>

class AdjacencyManager
{
	private:
		double** mat;
		int matSize;
	public:
		AdjacencyManager();
		void loadMatrix(double** newMat, int newMatSize);
		double pathWeight(std::vector<int> path);
};



#endif