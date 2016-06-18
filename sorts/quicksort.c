#include <stdlib.h>
#include <stdio.h>

// Theoretical O(nLog(n)) average algorithm.


void quick_sort(int unsortedList[], int listSize)
{
	int pivot, i, j, tmp;

	if (listSize < 2)
	{
		return;
	}

	// Choose pivot to be in the middle
	pivot = unsortedList[listSize / 2];

	for (i = 0, j = listSize - 1; 1; i++, j--)
	{

		while (unsortedList[i] < pivot)
		{
			i++;
		}

		while (pivot < unsortedList[j])
		{
			j--;
		}

		if (i >= j)
		{
			break;
		}

		// Swap i and j index
		tmp = unsortedList[j];
		unsortedList[j] = unsortedList[i];
		unsortedList[i] = tmp;

	}

	quick_sort(unsortedList, i);
	quick_sort(unsortedList + i, listSize - i);
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

	quick_sort(unsortedList, listSize);

	return 0;
}
