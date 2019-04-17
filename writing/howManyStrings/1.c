#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

int	main(void)
{
	FILE *x;
	int count = 1;
	int i = 0;

	x = fopen("x", "r");
	if (x == NULL)
	{
		printf("ERROR READING\n");
		exit(ERROR_FILE_OPEN);
	}
	do {
		i = fgetc(x);
		//printf("%c", i);
		if (i == '\n')
			count++;
	} while (i != EOF);
	fclose(x);
	printf("NUMBER OF LINES IS %d\n", count);
	return (0);
}