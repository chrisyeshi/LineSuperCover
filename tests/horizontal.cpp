#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
	// from [0.5, 0.5] dir [1.f, 0.f]
	{
		LineSuperCover cover(2, 2);
        std::vector<LineSuperCover::Index2> results = cover.rayCover(0.5f, 0.5f, 1.f, 0.f);
		LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(0,0), LineSuperCover::Index2(1, 0) };
		std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
		printAndCompare("#1 from [0.5, 0.5] dir [1.f, 0.f]", results, correct);
	}
	// from [0.0, 0.0] dir [1.0, 0.0]
	{
		LineSuperCover cover(2, 2);
        std::vector<LineSuperCover::Index2> results = cover.rayCover(0.f, 0.f, 1.f, 0.f);
		LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(0,0), LineSuperCover::Index2(1,0) };
		std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
		printAndCompare("#2 from [0.0, 0.0] dir [1.0, 0.0]", results, correct);
	}
	// from [1.99, 1.99] dir [-1.0, 0.0]
	{
		LineSuperCover cover(2, 2);
        std::vector<LineSuperCover::Index2> results = cover.rayCover(1.99f, 1.99f, -1.f, 0.f);
		LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(1,1), LineSuperCover::Index2(0,1) };
		std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
		printAndCompare("#3 from [1.99, 1.99] dir [-1.0, 0.0]", results, correct);
	}
	// from [1.0, 1.0] dir [-1.0, 0.0]
	{
		LineSuperCover cover(2, 2);
        std::vector<LineSuperCover::Index2> results = cover.rayCover(1.f, 1.f, -1.f, 0.f);
		LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(1,1), LineSuperCover::Index2(0,1) };
		std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
		printAndCompare("#4 from [1.99, 1.99] dir [-1.0, 0.0]", results, correct);
	}

	return 0;
}
