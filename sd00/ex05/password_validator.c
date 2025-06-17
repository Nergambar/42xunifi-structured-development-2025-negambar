#include "password_validator.h"
#include <stdbool.h>
#include <stdio.h>

size_t len(const char *s)
{
    int i = 0;
    while (s[i++]);
    return(i);
}


bool samesamebutdifferent(const char *new_pw, const char *curr_pw)
{
    bool wrong;
    size_t i = 0;
    size_t leng = 0;

    while (i < len(curr_pw))
        i++;
    if (i < len(new_pw))
        wrong = false;
    else
    {
        i = 0;
        while (i < len(new_pw))
        {
            if (new_pw[i] == curr_pw[i])
                leng++;
            i++;
        }
        if (leng == len(new_pw))
            wrong = true;
    }
    return (wrong);
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

    wrong = samesamebutdifferent(new_pw, curr_pw);
    i = 0;
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
    // printf("%d\n%d\n%d\n%d\n%d\n%d\n", wrong, digit, down, up, special, i);
    if (wrong || !digit || !down || !up || !special || i < 8)
        return result = 0;
    return result = 1;
}


/* int main(int ac, char **av)
{
    if (ac != 3)
        printf("aaaaaaaaaaaaaaaa");
    printf("password status: %d\n", validate_password(av[1], av[2]));
} */