#ifndef LINESUPERCOVER
#define LINESUPERCOVER

#include <vector>
#include <iostream>

class LineSuperCover
{
public:
	struct Index2
	{
		int x, y;
		Index2(int x, int y) : x(x), y(y) {}
		friend std::ostream& operator<<(std::ostream& out, const Index2& index2);
		friend bool operator==(const Index2& a, const Index2& b);
	};

public:
	LineSuperCover(int w, int h);
	~LineSuperCover() {}

	std::vector<Index2> traverse(float begX, float begY, float dirX, float dirY);

private:
	int gridW, gridH;

	std::vector<Index2> traverseRun(float begX, float begY, float dirX, float dirY);
	std::vector<Index2> traverseRise(float begX, float begY, float dirX, float dirY);
	void push_back(std::vector<Index2>& indices, Index2 index2);
};

#endif // LINESUPERCOVER