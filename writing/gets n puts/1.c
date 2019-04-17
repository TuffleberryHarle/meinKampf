#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

int	main(void)
{
	FILE *file;
	char c;

	file = fopen("x", "w+t");
	if (file == NULL)
	{
		printf("ERROR CREATING/OPENING\n");
		exit(ERROR_FILE_OPEN);
	}
	do {
		c = getchar();
		fputc(c, file);
		fputc(c, stdout);
	} while (c != 27);

	fclose(file);
	return (0);
}