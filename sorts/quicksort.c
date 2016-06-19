// Theoretical O(nLog(n)) average algorithm.
#include "quicksort.h"


void swap(int A[], int fo, int so)
{
	int tmp = A[fo];
	A[fo] = A[so];
	A[so] = tmp;
}


int medianOfThree(int A[], long lo, long hi)
{
	int mid = hi - (hi - lo) / 2;

	if (A[lo] > A[hi])
		swap(A, lo, hi);
	if (A[lo] > A[mid])
		swap(A, lo, mid);
	if (A[mid] > A[hi])
		swap(A, mid, hi);

	return A[mid];
}


int partition(int A[], long lo, long hi)
{
	int pivot;

	int i = lo - 1;
	int j = hi + 1;

	pivot = medianOfThree(A, lo, hi);

	while (1)
	{
		do i++; while (A[i] < pivot);
		do j--; while (A[j] > pivot);

		if (i >= j)
			return j;

		swap(A, i, j);
	}

}


void _quicksort(int A[], long lo, long hi)
{
	if (hi - lo < 2)
		return;

	int p = partition(A, lo, hi);

	_quicksort(A, lo, p);
	_quicksort(A, p + 1, hi);
}


void quicksort(int A[], long len)
{
	_quicksort(A, 0, len - 1);
}
