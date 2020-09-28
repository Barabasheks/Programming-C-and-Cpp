#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *dop_a, *a, *b;
	a = (char*)malloc(20);
	dop_a = (char*)malloc(10);
	b = (char*)malloc(10);
	gets(a);
	strcpy(dop_a, a);
	gets(b);
	
	printf("\n");
	strcat(a, b);
	printf("%s \n", a);
	
	if(strcmp(dop_a, b) == 0)
	{
		printf("strings are equivalent \n");
	}
	if(strcmp(dop_a, b) < 0)
	{
		printf("string 2 is bigger \n");
	}
	if(strcmp(dop_a, b) > 0)
	{
		printf("string 1 is bigger \n");
	}
	
	char *c;
	c = (char*)malloc(1);
	gets(c);
	int num = strcspn(dop_a, c) + 1;
	printf("number of symbol: %d \n", num);
	
	num = strcspn(dop_a, b) + 1;
	printf("number of symbol: %d \nsymbol: %c \n", num, dop_a[num-1]);
	
	int k = 0;
	do
	{
		k++;
		num = strcspn(dop_a, b);
		for(int i = 0; i < strlen(dop_a) - 1; i++)
		{
			dop_a[i] = dop_a[i + 1];
		}
	}while(num == 0);
	if(num != strlen(dop_a))
	{
		printf("%d", num);
	}
	else
	{
		printf("%d", num + 1 - k);
	}
	free(a);
	free(dop_a);
	free(b);
}
