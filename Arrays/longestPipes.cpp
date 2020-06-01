#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

static int bar_data[50];
static int max_length;
static int num_of_bars;
static int total_length;

int FindSum(int length, char* IsUsed)
{
	int i;

	printf("\n FindSum1: [%d] ", length);

	for (i = 0; i < num_of_bars; i++)
	{
		printf("%d ", IsUsed[i]);
	}
	printf("\n");

#if 0
	for (i = num_of_bars - 1; i >= 0; i--)
	{
		if ((IsUsed[i] == 0) && ((length - bar_data[i]) == 0))
		{
			IsUsed[i] = 1;
			return 1;
		}
	}
#endif

	for (i = num_of_bars - 1; i >= 0; i--)
	{
		if ((IsUsed[i] == 0) && ((length - bar_data[i]) >= 0))
		{
			IsUsed[i] = 1;
			length -= bar_data[i];

			if (length == 0)
			{
				return 1;
			}

			if (FindSum(length, IsUsed) == 0)
			{
				IsUsed[i] = 0;
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}

int CalculateHeight()
{
	int i = 0, j = 0, h1 = 0, h2 = 0;

	int max_height = 0;

	char IsUsed[51];

	for (i = num_of_bars - 1; i > 0; i--)
	{
		if (bar_data[i] > total_length)
		{
			j++;
			total_length -= bar_data[i];
		}
	}
	max_height = total_length / 2;
	num_of_bars -= j;

	j = 0;

	for (i = max_height; i > 1; i--)
	{
		memset(IsUsed, '\0', sizeof(IsUsed));

		h1 = FindSum(i, IsUsed);
		if (h1)
			h2 = FindSum(i, IsUsed);

		if (h1 & h2)
		{
			j = i;
			break;
		}
	}

	return j;
}


int main()
{
	int i;

	printf("\n Enter Number of Bars: ");
	scanf("%d", &num_of_bars);

	printf("\n Enter Bar Code Length's: ");
	total_length = 0;

	for (i = 0; i < num_of_bars; i++)
	{
		scanf("%d", &bar_data[i]);
		total_length += bar_data[i];
	}

	printf("\n Max Height: %d", CalculateHeight());

	getchar();

	return 0;
}
