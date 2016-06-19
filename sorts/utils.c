#include "utils.h"


void swap(int A[], int fo, int so)
{
	int tmp = A[fo];
	A[fo] = A[so];
	A[so] = tmp;
}
