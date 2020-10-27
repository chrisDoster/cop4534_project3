#include "parser.hpp"


double** Parser::buildEmptyMatrix()
{
	double** matrix = new double*[20];
	for (int i=0; i < 20; ++i)
	{
		matrix[i] = new double[20];
		for (int j=0; j < 20; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}


Parser::Parser()
{
	size.x = 0;
	size.y = 0;
}

double** Parser::parseAdjacencies(std::string fileName)
{
	double** matrix = nullptr;
	try
	{
		std::ifstream in(fileName);
		
		// build matrix and initialize with zeros
		matrix = buildEmptyMatrix();
		
		// find number of rows/cols
		
		
		// load matrix from file
		for (int i=0; i < 20; ++i)
		{
			for (int j=0; j < 20; ++j)
			{
				if (i == j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					matrix[i][j];
				}
			}
		}
	}
	catch (Exception e)
	{
		std::cout << "error opening file!! \n\n";
	}
}