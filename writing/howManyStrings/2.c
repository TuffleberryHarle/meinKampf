#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

int	main(void)
{
	FILE *x;
	int count = 1;
	//int i = 0;

	x = fopen("z", "r");
	if (x == NULL)
	{
		printf("ERROR READING\n");
		exit(ERROR_FILE_OPEN);
	}
	while (!feof(x))
	{
		fgetc(x) == '\n' ? count++ : 0;
	}
	fclose(x);
	count == 1 ? printf("NUMBER OF LINES IS %d OR IT'S EMPTY\n", count) :
	printf("NUMBER OF LINES IS %d\n", count);
	return (0);
}