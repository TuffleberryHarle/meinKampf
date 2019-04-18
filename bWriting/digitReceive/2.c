#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_OPEN_FILE -3
int main(void)
{
	FILE *f = NULL;
	int counter = 0, i = 0, num = 0;

	f = fopen("x", "rb");
	if (f == NULL)
	{
		printf("ERROR OPENING\n");
		exit(ERROR_OPEN_FILE);
	}
	fread(&counter, sizeof(int), 1, f);
	printf("THE NUMBER OF INTS IS %d\nAND THE INTS:\n", counter);
	while(i < counter) {
		fread(&num, sizeof(int), 1, f);
		printf("%d\n", num);
		i++;
	}
	fclose(f);
	return(0);
}