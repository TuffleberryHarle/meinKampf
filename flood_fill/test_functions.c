#include "test_functions.h"
#include "flood_fill.h"

char **make_area(char **zone)
{
	int i = 0;
	int j = 0;
	int str, stl;

	while (*zone[i])
	{
		while (zone [i][j])
			j++;
		j = 0;
		i++;
	}
	stl = j + 1;
}