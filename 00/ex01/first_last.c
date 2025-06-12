#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] == target)
        {
            *first = i;
            break;
        }
        i++;
    }
    if (arr[i] != target && i == size)
        *first = -1;
    i = size -1;
    while (i >= 0)
    {
        if (arr[i] == target)
        {
            *last = i;
            break;
        }
        i--;
    }
    if (arr[i] != target && i == 0)
        *last = -1;
}