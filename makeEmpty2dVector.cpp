#include "makeEmpty2dVector.h"

vVec makeEmpty2dVector(int row, int column)
{
	vVec temp;
	for (int i{}; i < row; i++)
	{
		vInt temp2;
		for (int j{}; j < column; j++)
		{
			temp2.push_back(0);
		}
		temp.push_back(temp2);
	}
	return temp;
}