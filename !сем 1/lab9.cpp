#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	switch(x)
	{
		case 0:
			printf("zero");
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
	}
	printf("\n \n");
	
	int months;
	float sum, rate;
	printf("sum: ");
	scanf("%f", &sum);
	printf("rate: ");
	scanf("%f", &rate);
	printf("months: ");
	scanf("%d", &months);
	for(int i = 1; i < months + 1; i++)
	{
		sum = sum + (rate / 12 / 100) * sum;
		printf("mon %d: %f \n", i, sum);
	}
}
