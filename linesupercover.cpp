#include "linesupercover.h"
#include <cmath>

std::ostream& operator<<(std::ostream& out, const Index2& index2)
{
	out << "[" << index2.x << "," << index2.y << "]";
	return out;
}

bool operator==(const Index2& a, const Index2& b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

LineSuperCover::LineSuperCover(int w, int h)
  : gridW(w), gridH(h)
{

}

std::vector<Index2> LineSuperCover::traverse(float begX, float begY, float dirX, float dirY)
{
	// traverse along the direction vector
	if (fabs(dirX) >= fabs(dirY))
		return traverseRun(begX, begY, dirX, dirY);
	else
		return traverseRise(begX, begY, dirX, dirY);
}

std::vector<Index2> LineSuperCover::traverseRun(float begX, float begY, float dirX, float dirY)
{
	std::vector<Index2> out;
	// real beginning cell
	int origX = int(std::floor(begX));
	int origY = int(std::floor(begY));
	push_back(out, Index2(origX, origY));
	int stepX = 0, stepY = 0;
	if (dirX > 0)
		stepX = 1;
	else if (dirX < 0)
		stepX = -1;
	if (dirY > 0)
		stepY = 1;
	else if (dirY < 0)
		stepY = -1;
	// traverse
	float yOx = dirY / dirX;
	int cellX, cellY;
	// first step from begX to center of the next cell
	if (stepX > 0)
	{
		cellX = (fmod(begX, 1.f) < 0.5f) ? origX : (origX + 1);
	} else {
		cellX = (1.f - fmod(begX, 1.f) < 0.5f) ? origX : (origX - 1);
	}
	float rayX = float(cellX) + 0.5f;
	float rayY = yOx * (rayX - begX) + begY;
	cellY = int(std::floor(rayY));
	if (cellX != origX || cellY != origY)
	{
		if ((stepX != 0 && cellX == origX + stepX) && (stepY != 0 && cellY == origY + stepY))
		{
			float ratioX = (stepX > 0) ? (float(cellX) - begX) : (begX - float(origX));
			float ratioY = (stepY > 0) ? (float(cellY) - begY) : (begY - float(origY));
			float ratioCellX = 0.5f;
			float ratioCellY = (stepY > 0) ? (rayY - float(cellY)) : (float(origY) - rayY);
			float targetY = 0.5f * ratioY / ratioX;
			if (ratioCellY < targetY) // bottom right square also
			{
				push_back(out, Index2(cellX, cellY - stepY));
			} else if (ratioCellY > targetY) // top left square also
			{
				push_back(out, Index2(cellX - stepX, cellY));
			}
		}
		push_back(out, Index2(cellX, cellY));
	}
	float error = 0.f;
	if (stepY > 0)
		error = fmod(rayY, 1.f);
	else if (stepY < 0)
		error = 1.f - fmod(rayY, 1.f);
	float deltaErr = fabs(yOx);
	// traverse
	while (!(cellX < 0 || cellX >= gridW || cellY < 0 || cellY >= gridH))
	{
		float errorNext = error + deltaErr;
		if (errorNext < 1.f)
		{
			cellX += stepX;
			push_back(out, Index2(cellX, cellY));
		} else
		{
			cellX += stepX;
			cellY += stepY;
			errorNext -= 1.f; // adjust error
			if (error + errorNext < 1.f) // bottom right square also
			{
				push_back(out, Index2(cellX, cellY - stepY));
				push_back(out, Index2(cellX, cellY));
			} else if (error + errorNext > 1.f) // top left square also
			{
				push_back(out, Index2(cellX - stepX, cellY));
				push_back(out, Index2(cellX, cellY));
			} else // only the top right square
			{
				push_back(out, Index2(cellX, cellY));
			}
		}
		// update error
		error = errorNext;
	}
	return out;
}

std::vector<Index2> LineSuperCover::traverseRise(float begX, float begY, float dirX, float dirY)
{
	std::vector<Index2> out;
	// real beginning cell
	int origX = int(std::floor(begX));
	int origY = int(std::floor(begY));
	push_back(out, Index2(origX, origY));
	int stepX = 0, stepY = 0;
	if (dirX > 0)
		stepX = 1;
	else if (dirX < 0)
		stepX = -1;
	if (dirY > 0)
		stepY = 1;
	else if (dirY < 0)
		stepY = -1;
	// traverse
	float xOy = dirX / dirY;
	int cellX, cellY;
	// first step from begX to center of the next cell
	if (stepY > 0)
	{
		cellY = (fmod(begY, 1.f) < 0.5f) ? origY : (origY + 1);
	} else {
		cellY = (1.f - fmod(begY, 1.f) < 0.5f) ? origY : (origY - 1);
	}
	float rayY = float(cellY) + 0.5f;
	float rayX = xOy * (rayY - begY) + begX;
	cellX = int(std::floor(rayX));
	if (cellX != origX || cellY != origY)
	{
		if ((stepX != 0 && cellX == origX + stepX) && (stepY != 0 && cellY == origY + stepY))
		{
			float ratioX = (stepX > 0) ? (float(cellX) - begX) : (begX - float(origX));
			float ratioY = (stepY > 0) ? (float(cellY) - begY) : (begY - float(origY));
			float ratioCellX = (stepX > 0) ? (rayX - float(cellX)) : (float(origX) - rayX);
			float ratioCellY = 0.5f;
			float targetX = 0.5f * ratioX / ratioY;
			if (ratioCellX < targetX) // top left square also
			{
				push_back(out, Index2(cellX - stepX, cellY));
			} else if (ratioCellX > targetX) // bottom right square also
			{
				push_back(out, Index2(cellX, cellY - stepY));
			}
		}
		push_back(out, Index2(cellX, cellY));
	}
	float error = 0.f;
	if (stepX > 0)
		error = fmod(rayX, 1.f);
	else if (stepX < 0)
		error = 1.f - fmod(rayX, 1.f);
	float deltaErr = fabs(xOy);
	// traverse
	while (!(cellX < 0 || cellX >= gridW || cellY < 0 || cellY >= gridH))
	{
		float errorNext = error + deltaErr;
		if (errorNext < 1.f)
		{
			cellY += stepY;
			push_back(out, Index2(cellX, cellY));
		} else
		{
			cellX += stepX;
			cellY += stepY;
			errorNext -= 1.f; // adjust error
			if (error + errorNext < 1.f) // top left square also
			{
				push_back(out, Index2(cellX - stepX, cellY));
				push_back(out, Index2(cellX, cellY));
			} else if (error + errorNext > 1.f) // bottom right square also
			{
				push_back(out, Index2(cellX, cellY - stepY));
				push_back(out, Index2(cellX, cellY));
			} else // only the top right square
			{
				push_back(out, Index2(cellX, cellY));
			}
		}
		// update error
		error = errorNext;
	}
	return out;
}

void LineSuperCover::push_back(std::vector<Index2>& indices, Index2 index2)
{
	if (index2.x < 0 || index2.x >= gridW || index2.y < 0 || index2.y >= gridH)
		return;
	indices.push_back(index2);
}