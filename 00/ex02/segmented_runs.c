#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
    int i = 0;
    int len = 0;
    int count = 0;
    while (i < size)
    {
        len = 0;
        if (arr[i] != -1)
        {
            while (i < size && arr[i] != -1)
            {
                if (arr[i + 1] == arr[i] + 1 || arr[i - 1] == arr[i] -1)
                    len++;
                i++;
            }
            if (len > 2)
               count++;
        }
        i++;
    }
    return(count);
}

int main(int ac, char **av)
{
    int arr[] = {2, 3, 4, 1, -1, 10, 11, 12, -1, 9, 2, -1};
    printf("%d\n", count_segments(arr, 16));
}