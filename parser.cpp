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

void Parser::calculateDimensions(std::string fileName)
{
	try
	{
		std::ifstream in(fileName);
		int numLines = 0;
		std::string line = "";
		while (getline(in, line))
		{
			numLines++;
		}
		// apply quadratic formula to find size of matrix
		double discriminant = 1 + 4*numLines;
		int arrSize = (int) (1 + sqrt(discriminant)) / 2;
		size.x = arrSize;
		size.y = arrSize;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR FINDING DIMENSIONS \n\n";
	}
}

void Parser::loadMatrixFromFile(double** matrix, std::string fileName)
{
	try
	{
		std::ifstream in(fileName);
		for (int i=0; i < size.x; ++i)
		{
			for (int j=0; j < size.y; ++j)
			{
				if (i == j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					std::string line = "-1.0";
					getline(in, line);
					double ijDist = stod(line);
					matrix[i][j] = ijDist;
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR LOADING MATRIX FROM FILE \n\n";
	}
}


Parser::Parser()
{
	size.x = 0;
	size.y = 0;
}

double** Parser::parseAdjacencies(std::string fileName)
{
	double** matrix = nullptr;
	
	matrix = buildEmptyMatrix();
	calculateDimensions(fileName);
	loadMatrixFromFile(matrix, fileName);
		
	return matrix;
}

int Parser::getDimensionSize()
{
	return size.x;
}

