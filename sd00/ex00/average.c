#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkvalid(int n)
{
    if (n >= 0 && n <= 100)
        return true;
    return false;
}

float average(int *arrn, int size)
{
    int i = 0;
    int add = 0;
    float res;

    while (i < size)
    {
        if (checkvalid(arrn[i]))
            add += arrn[i];
        i++;
    }
    res = (float)add / (float)size;
    return (res);
}