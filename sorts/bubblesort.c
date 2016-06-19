// Very inefficient sorting "algorithm". O(n*n) average.
#include "bubblesort.h"


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
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;

				haveSwapped = 1;
			}
		}

		if (!haveSwapped)
			break;
	}
}
