#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_valid(int n, bool *valid)
{
    if (n >= 0 && n <= 100)
        *valid = true;
    else
        *valid = false;
}


float average(int *arrn, int size)
{
    int i;
    int add;
    float res;
    bool valid;

    i = 0;
    add = 0;
    valid = true;
    while (i < size)
    {
        check_valid(arrn[i], &valid);
        if (valid)
            add += arrn[i];
        i++;
    }
    res = (float)add / (float)size;
    return (res);
}

/* #include <stdio.h>
int main()
{
    int arrn[] = {1, 2, 3, 4};
    int size = 4;
    printf("%4f\n", average(arrn, size));
} */