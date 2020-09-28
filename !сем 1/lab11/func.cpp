#include "func.h"
Triangle create(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Triangle obj;
	obj.xy[0][0] = x1;
	obj.xy[1][0] = x2;
	obj.xy[2][0] = x3;
	obj.xy[0][1] = y1;
	obj.xy[1][1] = y2;
	obj.xy[2][1] = y3;
	return(obj);
}

float perim(Triangle tr)
{
	int a, b;
	if(tr.xy[0][0] - tr.xy[1][0] != 0)
	{
		a = abs(tr.xy[0][0] - tr.xy[1][0]);
	}
	else 
	{
		a = abs(tr.xy[0][0] - tr.xy[2][0]);
	}
	if(tr.xy[0][1] - tr.xy[1][1] != 0)
	{
		b = abs(tr.xy[0][1] - tr.xy[1][1]);
	}
	else 
	{
		b = abs(tr.xy[0][1] - tr.xy[2][1]);
	}
	float c = sqrt(a*a + b*b);
	float p = a + b + c;
	return(p);
}

float square_tr(Triangle tr)
{
	float a, b;
	if(tr.xy[0][0] - tr.xy[1][0] != 0)
	{
		a = abs(tr.xy[0][0] - tr.xy[1][0]);
	}
	else 
	{
		a = abs(tr.xy[0][0] - tr.xy[2][0]);
	}
	if(tr.xy[0][1] - tr.xy[1][1] != 0)
	{
		b = abs(tr.xy[0][1] - tr.xy[1][1]);
	}
	else 
	{
		b = abs(tr.xy[0][1] - tr.xy[2][1]);
	}
	float s = a * b / 2;
	return(s);
}
