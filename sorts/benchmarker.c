#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "blahsort.h"
#include "bogosort.h"
#include "bubblesort.h"
#include "quicksort.h"


void populateRands(int A[], long len)
{
	for (long i = 0; i < len; i++)
		A[i] = rand() % 32768;
}


long callSorter(void (*sorter)(), int iter, long len)
{
	long elapsed = 0;
	struct timeval start, end;

	for (int i = 0; i < iter; i++)
	{
		// Generate random numbers
		int rands[len];
		populateRands(rands, len);

		gettimeofday(&start, NULL);
		sorter(rands, len);
		gettimeofday(&end, NULL);

		elapsed += 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	}

	return elapsed;
}


int main(int argc, char *argv[])
{
	int iter = 100;
	long len = 1000000;
	srand(time(NULL));

	if (argc > 1)
		iter = atoi(argv[1]);

	if (argc > 2)
	{
		char *tmp;
		len = strtol(argv[2], &tmp, 10);
	}

	// printf("Bogosort took %ldus.\n", callSorter(&bogosort, iter, len));
	printf("Bubblesort took %ldus.\n", callSorter(&bubble_sort, iter, len));
	printf("Quicksort took %ldus.\n", callSorter(&quicksort, iter, len));
	printf("Nand's magic took %ldus.\n", callSorter(&blah_sort, iter, len));

	return 0;
}
