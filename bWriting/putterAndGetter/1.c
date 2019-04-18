#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3

int main(void)
{
	FILE *f;
	int num;

	f = fopen("x", "wb"); // b is for binary, t is for text
	if (f == NULL)
	{
		printf("ERROR OPENING FILE\n");
		exit(ERROR_FILE_OPEN);
	}
	printf("TYPE IN AN INT NUMBER\n");
	scanf("%d", &num);
	fwrite(&num, sizeof(int), 1, f);

	fclose(f);
	return(0);
}