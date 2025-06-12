#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "critical_windows.h"

int count_critical_windows(const int *readings, int size)
{
    int i = 0;
    int count = 0;
    int len = 5;
    int add = 0;
    bool flag = false;
    while (i < size)
    {
        if (readings[i] <= 150 && readings[i] >= 70)
        {
            len--;
            add += readings[i];
            if (!flag)
                flag = true;
        }
        else
        {
            len = 5;
            flag = false;
            add = 0;
        }
        if (len == 0)
        {
            int res = add / 5;
            if (res >= 90)
                count++;
            len = 5;
            flag = false;
        }
        i++;
    }
    return (count);
}

/* int main()
{
    int arr[] = {101, 69, 111, 102, 150, 98, 71};
    int size = 7;
    printf("%d\n", count_critical_windows(arr, size));
} */