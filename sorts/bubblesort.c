#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

// Very inefficient sorting "algorithm". O(n*n) average.


void bubble_sort(int unsortedList[], int listSize)
{
	int haveSwapped;

	if (listSize < 2)
		return;

	for (int i = listSize; i > 1; i--)
	{
		haveSwapped = 0;

		for (int j = 0; j < i - 1; j++)
		{
			if (unsortedList[j] > unsortedList[j + 1])
			{
				int tmp = unsortedList[j];
				unsortedList[j] = unsortedList[j + 1];
				unsortedList[j + 1] = tmp;

				haveSwapped = 1;
			}
		}

		if (!haveSwapped)
			break;
	}
}


int main(int argc, char *argv[])
{
	int listSize = argc - 1;
	int unsortedList[listSize];

	struct timeval start, end;

	// Create our array
	for (int i = 0; i < listSize; i++)
		unsortedList[i] = atoi(argv[i + 1]);

	gettimeofday(&start, NULL);
	bubble_sort(unsortedList, listSize);
	gettimeofday(&end, NULL);

	printf("%ld\n", 1000000 * start.tv_sec + start.tv_usec - 1000000 * end.tv_sec + end.tv_usec);

	return 0;
}
