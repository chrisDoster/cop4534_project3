#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

class Parser
{
	struct Sizes { int x, y; };
	
	private:
		Sizes size;
		double** buildEmptyMatrix();
		void calculateDimensions(std::string fileName);
		void loadMatrixFromFile(double** matrix, std::string fileName);
		
	public:
		Parser();
		
		double** parseAdjacencies(std::string fileName);
		int getDimensionSize();
		
};



#endif