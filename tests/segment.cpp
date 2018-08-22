#include <cassert>
#include "common.h"
#include "linesupercover.h"

int main(void)
{
    // from [1.5, 1.5] to [3.5, 3.5]
    {
        LineSuperCover cover(5, 5);
        std::vector<LineSuperCover::Index2> results = cover.segmentCover(1.5f, 1.5f, 3.5f, 3.5f);
        LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(1, 1), LineSuperCover::Index2(2,2), LineSuperCover::Index2(3, 3) };
        std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
        printAndCompare("#1 from [1.5, 1.5] to [3.5, 3.5]", results, correct);
    }
    // from [1.9, 1.1] to [3.5, 3.5]
    {
        LineSuperCover cover(5, 5);
        std::vector<LineSuperCover::Index2> results = cover.segmentCover(1.9f, 1.1f, 3.5f, 3.5f);
        LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(1,1), LineSuperCover::Index2(2,1), LineSuperCover::Index2(2,2), LineSuperCover::Index2(3,2), LineSuperCover::Index2(3,3) };
        std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
        printAndCompare("#2 from [1.9, 1.1] to [3.5, 3.5]", results, correct);
    }
    // from [3.5, 2.1] to [1.5, 1.5]
    {
        LineSuperCover cover(5, 5);
        std::vector<LineSuperCover::Index2> results = cover.segmentCover(3.5f, 2.1f, 1.5f, 1.5f);
        LineSuperCover::Index2 correct_array[] = { LineSuperCover::Index2(3,2), LineSuperCover::Index2(3,1), LineSuperCover::Index2(2,1), LineSuperCover::Index2(1,1) };
        std::vector<LineSuperCover::Index2> correct(correct_array, correct_array + sizeof(correct_array) / sizeof(LineSuperCover::Index2));
        printAndCompare("#3 from [3.5, 2.1] to [1.5, 1.5]", results, correct);
    }
    return 0;
}
