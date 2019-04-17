#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FILE_OPEN -3

int main(void)
{
	FILE *file = NULL;
	char buf[500];
	char usrW[100];
	char engW[100];
	char rusW[200];
	int len = 0;
	int index;
	int flag = 0;

	printf("TYPE IN YOUR WORD: ");
	fgets(usrW, 99, stdin);
	printf("OK\n");
	
	file = fopen("x", "r");
	if (file == NULL)
	{
		printf("ERROR OPENING\n");
		exit(ERROR_FILE_OPEN);

	}

	while (!feof(file))
	{
		fgets(buf, 499, file);
		len = strlen(buf);
		for (index = 0; index < len; index++) 
		{
            if (buf[index] == '\t') 
            {
                buf[index] = '\0';
                break;
            }
        }
        strcpy(rusW, buf);
        strcpy(engW, &buf[index + 1]);

        if (!(strcmp(engW, usrW)))
        {
        	flag = 1;
        	break;
        }
    }

	if (flag)
		printf("%s\n", rusW);
	else
		printf("NOT FOUND\n");

	fclose(file);
	return (0);
}