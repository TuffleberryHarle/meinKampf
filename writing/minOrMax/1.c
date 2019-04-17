#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
#define ERROR_FILE_OPEN -3

int main(void)
{
	FILE *file;
	int num, min, flag;

	file = fopen("x", "r");
	if (file == NULL)
	{
		printf("ERROR READING\n");
		exit(ERROR_FILE_OPEN);
	}
	min = INT_MAX;
	flag = 1;
	while (flag == 1)
	{
		flag = fscanf(file, "%d", &num);
		if (flag != 1)
			continue;
		min = (num < min) ? num : min;
	}
	printf("smallest %d\n", min);
	fclose(file);
	return (0);
}