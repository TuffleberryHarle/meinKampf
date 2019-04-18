#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10

int main(void)
{
	FILE *file = NULL;
	const char fname[] = "head";
	int position, value = 0, i = 0, flag;
	do {
		flag = 0;
		file = fopen(fname, "r+b");
		if (file == NULL)
		{
			printf("WAIT TIL I CREATE IT\n");
			file = fopen(fname, "wb");
			if (file == NULL)
			{
				printf("CAN'T DO SHIT, SORRY\n");
				exit(1);
			}
			while(i < SIZE)
			{
				fwrite(&value, sizeof(int), 1, file);
				i++;
			}
			printf("DONE CREATING\n");
			fclose(file);
			flag = 1;
		}
	} while (flag);

	do {
		printf("ENTER NEEDED POSITION FROM 0 TO 9 REAL QUICK!\n");
		scanf("%d", &position);
		if (position < 0 || position >= SIZE)
			break;
		printf("ENTER YOUR VALUE REAL QUICK!\n");
		scanf("%d", &value);
		fseek(file, position*sizeof(int), SEEK_SET);
		fwrite(&value, sizeof(int), 1, file);
		rewind(file);
		i = 0;
		while(i < SIZE)
		{
			fread(&value, sizeof(int), 1, file);
			printf("%d ", value);
			i++;
		}
		printf("\n");
	} while(1);

	fclose(file);
	return(0);
}