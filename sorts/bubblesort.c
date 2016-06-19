// Very inefficient sorting "algorithm". O(n*n) average.
#include "bubblesort.h"
#include "utils.h"


void bubble_sort(int A[], long len)
{
	int haveSwapped;

	if (len < 2)
		return;

	for (long i = len; i > 1; i--)
	{
		haveSwapped = 0;

		for (long j = 0; j < i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A, j, j + 1);
				haveSwapped = 1;
			}
		}

		if (!haveSwapped)
			break;
	}
}
