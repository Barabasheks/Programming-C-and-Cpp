#include <stdio.h>
#include "func.h"

int main()
{
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	Triangle tr = create(x1, y1, x2, y2, x3, y3);
	float p = perim(tr);
	float s = square_tr(tr);
	printf("p = %f \ns = %f", p, s);
}
