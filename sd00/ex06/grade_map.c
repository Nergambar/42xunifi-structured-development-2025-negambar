typedef char *(*GradeMapper)(int);
#include <stdlib.h>

char *plusminus_mapper(int grade)
{
    
    if (grade >= 97 && grade <= 100)
        return ("A+");
    if (grade >= 93 && grade <= 96)
        return ("A");
    if (grade >= 90 && grade <= 92)
        return ("A-");
    if (grade >= 87 && grade <= 89)
        return ("B+");
    if (grade >= 83 && grade <= 86)
        return ("B");
    if (grade >= 80 && grade <= 82)
        return ("B-");
    if (grade >= 77 && grade <= 79)
        return ("C+");
    if (grade >= 73 && grade <= 76)
        return ("C");
    if (grade >= 70 && grade <= 72)
        return ("C-");
    if (grade >= 67 && grade <= 69)
        return ("D+");
    if (grade >= 63 && grade <= 66)
        return ("D");
    if (grade >= 60 && grade <= 62)
        return ("D-");
    if (grade <= 59 && grade >= 0)
        return ("F");
    return (NULL);
}

char *passfail_mapper(int grade)
{
    if (grade >= 60 && grade <= 100)
        return ("P");
    else if (grade >= 0 && grade <= 59)
        return ("F");
    return (NULL);
}
char *standard_mapper(int grade)
{
    if (grade >= 90 && grade <= 100)
        return ("A");
    if (grade >= 80 && grade <= 89)
        return ("B");
    if (grade >= 70 && grade <= 79)
        return ("C");
    if (grade >= 60 && grade <= 69)
        return ("D");
    if (grade <= 59 && grade > -1)
        return ("F");
    return (NULL);
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        mapped_grades[i] = mapper(scores[i]);
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