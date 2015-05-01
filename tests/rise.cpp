#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
	// from [0.25, 0.25] dir [0.9, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.25f, 0.25f, 0.99f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(0,1), Index2(1,1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#1 from [0.25, 0.25] dir [0.9, 1.0]", results, correct);
	}
	// from [0.75, 0.25] dir [0.9, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.75f, 0.25f, 0.99f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(1,0), Index2(1,1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#2 from [0.75, 0.25] dir [0.9, 1.0]", results, correct);
	}
	// from [0.25, 0.75] dir [0.9, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.25f, 0.75f, 0.99f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(0,1), Index2(1,1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#3 from [0.25, 0.75] dir [0.9, 1.0]", results, correct);
	}
	// from [0.75, 0.75] dir [0.9, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.75f, 0.75f, 0.99f, 1.f);
		Index2 correct_array[] = { Index2(0,0), Index2(0,1), Index2(1,1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#4 from [0.75, 0.75] dir [0.9, 1.0]", results, correct);
	}
	// from [1.5, 0.5] dir [-0.9 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(1.5f, 0.5f, -0.9f, 1.f);
		Index2 correct_array[] = { Index2(1,0), Index2(1,1), Index2(0,1) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#5 from [1.5, 0.5] dir [-0.9 1.0]", results, correct);
	}
	// from [0.5, 1.5] dir [0.9, -1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(0.5f, 1.5f, 0.9f, -1.f);
		Index2 correct_array[] = { Index2(0,1), Index2(0,0), Index2(1,0) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#6 from [0.5, 1.5] dir [0.9, -1.0]", results, correct);
	}
	// from [1.5 1.5] dir [-0.9, -1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(1.5f, 1.5f, -0.9f, -1.f);
		Index2 correct_array[] = { Index2(1,1), Index2(1,0), Index2(0,0) };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#7 from [1.5 1.5] dir [-0.9, -1.0]", results, correct);
	}
	// from [-1.5, -1.5] dir [0.9, 1.0]
	{
		LineSuperCover cover(2, 2);
		std::vector<Index2> results = cover.traverse(-1.5f, -1.5f, 0.9f, 1.f);
		Index2 correct_array[] = { };
		std::vector<Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(Index2));
		printAndCompare("#8 [-1.5 -1.5] dir [0.9, 1.0]", results, correct);
	}

	return 0;
}