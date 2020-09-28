#ifndef FUNC_H
#define FUNC_H
#include <math.h>
struct Triangle
{
	int xy[3][2];
};

float perim(Triangle tr);
float square_tr(Triangle tr);
Triangle create(int x1, int y1, int x2, int y2, int x3, int y3);
#endif
