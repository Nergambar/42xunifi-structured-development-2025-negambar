typedef char *(*GradeMapper)(int);
#include <stdlib.h>

void plusminus_mapper(int grade, char **alpha)
{
    
    if (grade >= 97 && grade <= 100)
        *alpha = "A+";
    else if (grade >= 93 && grade <= 96)
        *alpha = "A";
    else if (grade >= 90 && grade <= 92)
        *alpha = "A-";
    else if (grade >= 87 && grade <= 89)
        *alpha = "B+";
    else if (grade >= 83 && grade <= 86)
        *alpha = "B";
    else if (grade >= 80 && grade <= 82)
        *alpha = "B-";
    else if (grade >= 77 && grade <= 79)
        *alpha = "C+";
    else if (grade >= 73 && grade <= 76)
        *alpha = "C";
    else if (grade >= 70 && grade <= 72)
        *alpha = "C-";
    else if (grade >= 67 && grade <= 69)
        *alpha = "D+";
    else if (grade >= 63 && grade <= 66)
        *alpha = "D";
    else if (grade >= 60 && grade <= 62)
        *alpha = "D-";
    else if (grade <= 59 && grade >= 0)
        *alpha = "F";
    else
        *alpha = NULL;
}

void passfail_mapper(int grade, char **alpha)
{
    if (grade >= 60 && grade <= 100)
        *alpha ="P";
    else if (grade >= 0 && grade <= 59)
        *alpha = "F";
    else
        *alpha = NULL;
}
void standard_mapper(int grade, char **alpha)
{
    if (grade >= 90 && grade <= 100)
        *alpha = "A";
    else if (grade >= 80 && grade <= 89)
        *alpha = "B";
    else if (grade >= 70 && grade <= 79)
        *alpha = "C";
    else if (grade >= 60 && grade <= 69)
        *alpha = "D";
    else if (grade <= 59 && grade > -1)
        *alpha = "F";
    else
        *alpha = NULL;
}
typedef void (*MapperFunc)(int, char **);

void map_scores(const int *scores, int size, MapperFunc mapper, const char **mapped_grades)
{
    for (int i = 0; i < size; i++)
    {
        char *alpha = NULL;
        mapper(scores[i], &alpha);
        mapped_grades[i] = alpha;
    }
}

#include <stdio.h>
int main(void)
{
    int scores[] = {98, 95, 91, 88, 85, 81, 78, 74, 71, 68, 65, 61, 59};
    int size = sizeof(scores) / sizeof(scores[0]);
    const char *mapped_grades[size];
    map_scores(scores, size, plusminus_mapper, mapped_grades);
    for (int i = 0; i < size; i++)
        printf("Score %d: %s\n", scores[i], mapped_grades[i]);

    return 0;
}