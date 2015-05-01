#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "linesupercover.h"

void printAndCompare(const std::string& header, const std::vector<LineSuperCover::Index2>& results, const std::vector<LineSuperCover::Index2>& correct)
{
	std::cout << header << std::endl;
	std::cout << "Results: ";
	for (unsigned int i = 0; i < results.size(); ++i)
		std::cout << results[i] << ", ";
	std::cout << std::endl;
	std::cout << "Correct: ";
	for (unsigned int i = 0; i < correct.size(); ++i)
		std::cout << correct[i] << ", ";
	std::cout << std::endl;
	assert(results == correct);
}