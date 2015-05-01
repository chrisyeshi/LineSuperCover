#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
	// from [0.5, 0.5] dir [0.0, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.5f, 0.5f, 0.f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(0, 1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#1 from [0.5, 0.5] dir [0.0, 1.0]", results, correct);
	}
	// from [0.0, 0.0] dir [0.0, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.f, 0.f, 0.f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(0, 1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#2 from [0.0, 0.0] dir [0.0, 1.0]", results, correct);
	}

	return 0;
}