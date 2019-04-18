#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3
 
int main(void) 
{
    FILE *f = NULL;
    int num;
 
    f = fopen("x", "w+b");
    if (f == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 	
 	printf("PUT IN AN INT: ");
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);
    num = 0;
    fread(&num, sizeof(int), 1, f);
    printf("%d", num);
 
    fclose(f);
    return (0);
}