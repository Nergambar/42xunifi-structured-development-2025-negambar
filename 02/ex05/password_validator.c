#include "password_validator.h"
#include <stdbool.h>
#include <stdio.h>

void len(const char *s, size_t *lent)
{
    *lent = 0;
    while (s[*lent])
        (*lent)++;
}


void samesamebutdifferent(const char *new_pw, const char *curr_pw, bool *wrong)
{
    size_t longg;
    size_t i = 0;
    size_t leng = 0;

    len(curr_pw, &longg);
    while (i < longg)
        i++;
    len(new_pw, &longg);
    if (i < longg)
        *wrong = false;
    else
    {
        i = 0;
        while (i < longg)
        {
            if (new_pw[i] == curr_pw[i])
                leng++;
            i++;
        }
        if (leng == longg)
            *wrong = true;
    }
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    int i = 0;
    PwStatus result;
    bool wrong = false;
    bool up = false;
    bool down = false;
    bool digit = false;
    bool special = false;

    samesamebutdifferent(new_pw, curr_pw, &wrong);
    i = 0;
    if (wrong)
        return result = 1;
    while (new_pw[i])
    {
        if (new_pw[i] >= '0' && new_pw[i] <= '9')
            digit = true;
        if (new_pw[i] >= 'a' && new_pw[i] <= 'z')
            down = true;
        if (new_pw[i] >= 'A' && new_pw[i] <= 'Z')
            up = true;
        if (new_pw[i] < '0' && (new_pw[i] != ' ')
        || (new_pw[i] > '9' && new_pw[i] < 'A')
        || (new_pw[i] > 'Z' && new_pw[i] < 'a')
        || new_pw[i] > 'z')
            special = true;
        i++;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", wrong, digit, down, up, special, i);
    if (wrong || !digit || !down || !up || !special || i < 8)
        return result = 1;
    return result = 0;
}


int main()
{
    printf("password status: %d\n", validate_password( "Ciao12!", "Ciao12!"));
}