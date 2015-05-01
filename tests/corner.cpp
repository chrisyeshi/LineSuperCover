#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
	LineSuperCover cover(2, 2);
	std::vector<Index2> results = cover.traverse(0.f, 0.f, 1.f, 1.f);
	Index2 correct_array[] = { Index2(0,0), Index2(1, 1) };
	std::vector<Index2> correct(correct_array, correct_array + 2);
	printAndCompare("corner case", results, correct);
	return 0;
}