#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//Имена файлов и права доступа
#define INPUT_FILE  "input.txt"
#define OUTPUT_FILE "output.txt"
#define READ_ONLY  "r"
#define WRITE_ONLY "w"
//Максимальное значение для размера массива
#define MAX_DIMENSION 10
//Ошибка при открытии файла
#define ERROR_OPEN_FILE -3

int	main(void)
{
	FILE *input = NULL;
	FILE *output = NULL;
    char first[3], sec[3];
    char a[10];
    unsigned a0, a1;
    //unsigned a[] = {2,4};

    unsigned i = 0, j = 0;
 
    input = fopen(INPUT_FILE, READ_ONLY);
    if (input == NULL) {
        printf("Error opening file input");
        exit(ERROR_OPEN_FILE);
    }
    output = fopen(OUTPUT_FILE, WRITE_ONLY);
    if (output == NULL) {
        printf("Error opening file output");
        if (input != NULL) fclose(input);
        exit(ERROR_OPEN_FILE);
    }

    //fscanf(input, "%ui\n%ui", &a[0], &a[1]);
    fgets(a, 9, input);
    while (a[i] != ' ') {
    	first[i] = a[i];
    	i++;}
    first[i++] = '\0';
    while (a[i])
    {
		sec[j] = a[i++];
    	j++;
    }
    sec[j] = '\0';
    a0 = atoi(first);
    a1 = atoi(sec);
    a0 = (a0 >= MAX_DIMENSION) ? MAX_DIMENSION : a0;
    a1 = (a1 >= MAX_DIMENSION) ? MAX_DIMENSION : a1;
    srand(time(NULL));
    i = 0;
    while (i < a0)
    {
    	j = 0;
    	while (j < a1)
    	{
    		fprintf(output, "%3d ", rand());
    		j++;
    	}
    	
    	i++;
        (i == a0) ? 0 : fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);
	return (0);
}