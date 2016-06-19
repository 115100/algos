#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "blahsort.h"

#define MIN -32768
#define MAX 32768

void blah_sort(int a[], long len)
{
    const size_t num = MAX - MIN;
	short *count;

	if ((count = malloc(sizeof(short) * num)) == NULL)
		abort();

    memset(count, 0, sizeof(short) * num);

    for (int i = 0; i < len; i++)
        count[a[i] - MIN]++;

    int pos = 0;
    for (int i = 0; i < num; i++) {
        while (count[i]-- > 0)
            a[pos++] = i + MIN;
    }

    free(count);
}
