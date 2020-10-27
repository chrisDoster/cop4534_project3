#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <fstream>

class Parser
{
	private:
		struct size { int x, y; };
		double** buildEmptyMatrix();
	public:
		Parser();
		
		double** parseAdjacencies(std::string fileName);
};



#endif