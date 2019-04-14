#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

int main(void)
{
	FILE *source = NULL;
	FILE *output = NULL;
	char fileName[20];
	unsigned mode;

	printf("ENTER THE FILENAME REAL QUICK:\n>> ");
	scanf("%19s", fileName);
	printf("\n");
	source = fopen(fileName, "r");
	if (source == NULL)
	{
		printf("ERROR OPENING %s\n", fileName);
		exit(ERROR_FILE_OPEN);
	}
	printf("CHOOSE THE MODE:\n1 -- COPY\n2 -- PRINT\n>> ");
	scanf("%ui", &mode);

	if (mode == 1)
	{
		printf("ENTER THE NEW FILENAME:\n>>");
		scanf("%19s", fileName);
		output = fopen(fileName, "w");
		if (output == NULL)
		{
			printf("ERROR OPENING %s\n", fileName);
			fclose(source);
			exit(ERROR_FILE_OPEN);
		}
		else 
			printf("%s SUCCESSFULLY CREATED\n", fileName);

	}
	else {
		output = stdout;
		printf("\n");
		printf("%s CONTAINS:\n", fileName);

	}

	while(!feof(source))
		fprintf(output, "%c", fgetc(source));

	fclose(output);
	fclose(source);
}