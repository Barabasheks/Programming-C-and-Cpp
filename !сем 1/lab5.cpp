#include <stdio.h>

int main()
{
	int x[8];
	for(int i = 0; i < 8; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("\n");
	for(int i = 0; i < 8; i++)
	{
		printf("%d ", x[i]);
	}
	
	int m1[2][2], m2[2][2], m3[2][2];
	m1[0][0] = 1;
	m1[0][1] = 0;
	m1[1][0] = 0;
	m1[1][1] = 1;
	
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;
	m2[1][1] = 1;
	
	m3[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
	m3[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
	m3[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
	m3[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
	
	printf("\n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("%d ", m3[i][j]);
		}
		printf("\n");
	}
}
