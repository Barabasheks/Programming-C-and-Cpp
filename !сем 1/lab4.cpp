#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	bool rez = (x >= -56) && (x <= 56);
	printf("prinadlegnost' intevalu [-56;56]: %d \n", rez);
	
	scanf("%d", &x);
	int y = 256;
	y = y & x;
	y = y >> 8;
	printf("%d", y);
}
