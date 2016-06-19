// O(n!) joke algorithm. Don't benchmark this with high len.
#include <stdlib.h>

#include "utils.h"


int sorted(int A[], long n)
{
	while (--n >= 1)
	{
		if (A[n] < A[n-1])
			return 0;
	}

	return 1;
}


void shuffle(int A[], long len)
{
	int ri;

	for (int i = 0; i < len; i++)
	{
		ri = rand() % len;
		swap(A, i, ri);
	}
}


void bogosort(int A[], long len)
{
	while (!sorted(A, len))
		shuffle(A, len);
}
