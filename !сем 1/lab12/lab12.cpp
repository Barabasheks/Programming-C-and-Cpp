#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	char* file = (char*)malloc(10);
	FILE *f1, *f2, *f3;
	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	f3 = fopen(argv[3], "w");
	if(f1 != NULL && f2 != NULL)
	{
		while(fgets(file, 10, f1) != NULL)
		{
			fputs(file, f3);
		}
		while(fgets(file, 10, f2) != NULL)
		{
			fputs(file, f3);
		}	
	}
	else
	{
		printf("Wrong name of file");
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
