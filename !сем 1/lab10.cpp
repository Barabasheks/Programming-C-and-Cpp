#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* n_to_array(int n)
{
	int *arr = (int*)malloc(sizeof(int));
	int i = 0;
	while(n > 0)
	{
		arr[i] = n % 10;
		i++;
		n = n / 10;
		realloc(arr, (i + 1)*sizeof(int));
	}
	return(arr);
}

char* del_el(char* str, int j)
{
	for(j; j < strlen(str); j++)
	{
		str[j] = str[j + 1];
	}
	return(str);
}

char* string(char* str, int i)
{
	char last_symbol = str[i - 1];
	char last_last_symbol = str[i - 2];
	if(last_symbol == ' ' && last_last_symbol == ' ' && str[i] == ' ')
	{
		str = del_el(str, i);
	}
	else if((last_symbol == '(' || last_symbol == '{' || last_symbol == '[') && str[i] == ' ')
	{
		str = del_el(str, i);
	}
	else
		i++;
	if(i < strlen(str))
	{
		str = string(str, i);
	}
	else
	{
		i = strlen(str) - 1;
		while(str[i] != '.' && i != 0) 
		{
			i--;
		}
		if(i != 0)
		{
			int j = strlen(str) - 1;
			while(j > i)
			{
				if(str[j] == ' ')
				{
					str = del_el(str, j);
				}
				j--;
			}
		} 
		return(str);	
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = n_to_array(n);
	int i = 0;
	while(n > 0)
	{
		printf("%d ", arr[i]);
		i++;
		n = n / 10;
	}
	printf("\n");
	int size;
	scanf("%d\n", &size);
	char *str = (char*)malloc(size * sizeof(char));
	gets(str);
	str = string(str, 2);
	printf("%s", str);
}
