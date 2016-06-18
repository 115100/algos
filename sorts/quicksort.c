#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

// Theoretical O(nLog(n)) average algorithm.

void swap(int A[], int fo, int so)
{
	int tmp = A[fo];
	A[fo] = A[so];
	A[so] = tmp;
}


int medianOfThree(int A[], int lo, int hi)
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


int partition(int A[], int lo, int hi)
{
	int pivot;

	int i = lo - 1;
	int j = hi + 1;

	// // Get median of three
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

	struct timeval start, end;

	// Create our array
	for (int i = 0; i < listSize; i++)
		unsortedList[i] = atoi(argv[i + 1]);

	gettimeofday(&start, NULL);
	quicksort(unsortedList, 0, listSize - 1);
	gettimeofday(&end, NULL);

	printf("%ld\n", 1000000 * start.tv_sec + start.tv_usec - 1000000 * end.tv_sec + end.tv_usec);

	return 0;
}
