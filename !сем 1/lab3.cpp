#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void x_to_16(int x)
{
	if(x == 0)
	{
		printf("0");
		return;
	}
	bool flag = false;
	if(x < 0){
		x = x * (-1);
		flag = true;
	}
	int i = 0;
	int dopx = x;
	while(dopx > 0)
	{
		dopx = dopx / 16;
		i++;
	}
	char x16[i];
	int n = i;
	dopx = x;
	i = 0;
	while(dopx > 0)
	{
		int ost = dopx % 16;
		dopx = dopx / 16;
		if(ost < 10)
		{
			x16[n - 1 - i] = (char)(48 + ost);
		}
		else
		{
			x16[n - 1 - i] = (char)(55 + ost);
		}
		i++;
	}
	if(flag)
	{
		printf("-");
	}
	for(int i = 0; i < n; i++)
	{
		printf("%c", x16[i]);
	}
}

int main()
{
	int x;
	scanf("%o", &x);
	int x8 = 0, i = 1, dopx = x;
	printf("%d \n \n", x);
	
	x_to_16(x);
	printf("\n");
	x_to_16(x >> 4);
	printf("\n \n");

	x_to_16(x);
	printf("\n");
	x_to_16(~x);
	printf("\n \n");
	
	int int_y;
	scanf("%x", &int_y);
	
	int not_or = int_y ^ x;
	printf("%x", not_or);
}
