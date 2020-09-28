#include <stdio.h>

enum Lamp
{
	nakalivania = 3,
	dnevnogo_sveta = 3,
	galogennie = 3,
	gazovie,
	svetodiodnie
};

struct Triangle_pr
{
	int xy[3][2], a1, a2, a3, p;
};

union
{
	short int x;
	struct {
		unsigned on_off : 1;
		unsigned sd : 1;
		unsigned compact_flash : 1;
		unsigned memory_stick : 1;
	} elements;
} Card_reader;

int main()
{
	Lamp g = galogennie;
	printf("%d \n", g);
	
	Triangle_pr tr;
	tr.xy[0][0] = 0; 
	tr.xy[0][1] = 0;
	tr.xy[1][0] = 0; 
	tr.xy[1][1] = 3;
	tr.xy[2][0] = 4; 
	tr.xy[2][1] = 0;
	tr.a1 = 3;
	tr.a2 = 4;
	tr.a3 = 5;
	tr.p = tr.a1 + tr.a2 + tr.a3;
	printf("%d \n", tr.p);
	
	short int x;
	scanf("%hx", &x);
	Card_reader.x = x;
	if(Card_reader.elements.on_off == 0) printf("card_reader: off \n");
	else printf("card_reader: on \n");
	if(Card_reader.elements.sd == 0) printf("sd: off \n");
	else printf("sd: on \n");
	if(Card_reader.elements.compact_flash == 0) printf("compact_flash: off \n");
	else printf("compact_flash: on \n");
	if(Card_reader.elements.memory_stick == 0) printf("memory_stick: off \n");
	else printf("memory_stick: on \n");
}
