#include <stdlib.h>
#include <stdio.h>

// Theoretical O(nLog(n)) average algorithm.

int partition(int A[], int lo, int hi)
{
	int pivot;

	int i = lo - 1;
	int j = hi + 1;

	// // Get median of three
	int mid = j - (j - i) / 2;

	// Arrange so that A[lo] <= A[mid] <= A[hi]
	// Writing a swap function would probably increase
	// function call overhead quite a bit?
	int tmp;
	if (A[lo] > A[hi])
	{
		tmp = A[lo];
		A[lo] = A[hi];
		A[hi] = tmp;
	}
	if (A[lo] > A[mid])
	{
		tmp = A[lo];
		A[lo] = A[mid];
		A[mid] = tmp;
	}
	if (A[mid] > A[hi])
	{
		tmp = A[mid];
		A[mid] = A[hi];
		A[hi] = tmp;
	}

	pivot = A[mid];

	while (1)
	{
		do i++; while (A[i] < pivot);
		do j--; while (A[j] > pivot);

		if (i >= j)
			return j;

		int tmp;
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}

}


void quicksort(int A[], int lo, int hi)
{
	if (hi - lo < 2) return;

	int p = partition(A, lo, hi);

	quicksort(A, lo, p);
	quicksort(A, p + 1, hi);
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

	quicksort(unsortedList, 0, listSize - 1);

	return 0;
}
