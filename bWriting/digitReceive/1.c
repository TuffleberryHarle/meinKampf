#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_OPEN_FILE -3

int main(void)
{
	FILE *f = NULL;
	int counter = 0, num, choice;

	f = fopen("x", "w+b");
	if (f == NULL)
	{
		printf("ERROR OPENING\n");
		exit(ERROR_OPEN_FILE);
	}

	fwrite(&counter, sizeof(int), 1, f);
	do {
		printf("CHOOSE:\n1 -- ADD\n2 -- ENOUGH\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			scanf("%d", &num);
			fwrite(&num, sizeof(int), 1, f);
			counter++;
		}
		else
		{
			rewind(f);
			fwrite(&counter, sizeof(int), 1, f);
			break;
		}
	} while (1);
	fclose(f);
	return (0);
}