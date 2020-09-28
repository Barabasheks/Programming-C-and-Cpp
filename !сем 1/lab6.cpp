#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m[4];
	int *x = m;
	for(int i = 0; i < 4; i++)
	{
		scanf("%d", &m[i]);
	}
	for(int i = 0; i < 4; i++)
	{
		printf("%d ", *(x+i));
	}
	printf("\n");
	
	int *a;
	a = (int*)malloc(4*sizeof(int));
	for(int i = 0; i < 4; i++)
	{
		scanf("%d", &m[i]);
	}
	for(int i = 0; i < 4; i++)
	{
		printf("%d ", *(x+i));
	}
	free(a);
}
