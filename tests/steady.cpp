#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
	// from [1.5, 1.5] dir [0.f, 0.f]
	{
		LineSuperCover cover(3, 3);
		std::vector<LineSuperCover::Index2> results = cover.traverse(1.5f, 1.5f, 0.f, 0.f);
		LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(1, 1) };
		std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
		printAndCompare("#1 from [1.5, 1.5] dir [0.f, 0.f]", results, correct);
	}

	return 0;
}