#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3

int main(void)
{
	FILE *f;
	int num;

	f = fopen("x", "rb"); // b is for binary, t is for text
	if (f == NULL)
	{
		printf("ERROR OPENING FILE\n");
		exit(ERROR_FILE_OPEN);
	}
	fread(&num, sizeof(int), 1, f);
	printf("%d\n", num);

	fclose(f);
	return (0);
}