#include <stdlib.h>
#include <stdio.h>

// Very inefficient sorting "algorithm". O(n*n) average.


void bubble_sort(int unsortedList[], int listSize)
{
	int tmp, haveSwapped;

	if (listSize < 2)
	{
		return;
	}

	for (int i = listSize; i > 1; i--)
	{
		haveSwapped = 0;

		for (int j = 0; j < i - 1; j++)
		{
			if (unsortedList[j] > unsortedList[j + 1])
			{
				tmp = unsortedList[j];
				unsortedList[j] = unsortedList[j + 1];
				unsortedList[j + 1] = tmp;

				haveSwapped = 1;
			}
		}

		if (!haveSwapped)
		{
			break;
		}
	}
}


int main(int argc, char *argv[])
{
	int listSize = argc - 1;
	int unsortedList[listSize];

	// Create our array
	for (int i = 0; i < listSize; i++)
	{
		unsortedList[i] = atoi(argv[i + 1]);
	}

	bubble_sort(unsortedList, listSize);

	return 0;
}
