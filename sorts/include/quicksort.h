#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int A[], int fo, int so);
int medianOfThree(int A[], long lo, long hi);
int partition(int A[], long lo, long hi);
void _quicksort(int A[], long lo, long hi);
void quicksort(int A[], long len);

#endif // QUICKSORT_H
