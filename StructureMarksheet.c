#include <stdio.h>

struct student
{
    int rno;
    char name[10];
    int marks[5];
}s[3];

int main()
{
    int i, j;
    int topper[5];

    for (i = 0; i < 3; i++)
    {
        printf("Enter details of student:-\n");
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter rollno: \n");
        scanf("%d", &s[i].rno);
        printf("Enter marks for 5 subjects: \n");
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
        }
    }

    printf("-----Marksheet-----\n");
    printf("RollNo\tName\t\tEnglish\tHindi\tMaths\tScience\tSst\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d\t%-10s\t", s[i].rno, s[i].name);
        for (j = 0; j < 5; j++)
        {
            printf("%d\t", s[i].marks[j]);
        }
        printf("\n");
    }

    printf("\n-----Subject Wise Topper-----\n");

    topper[0] = 0;
    for (i = 1; i < 3; i++)
    {
        if (s[i].marks[0] > s[topper[0]].marks[0])
        {
            topper[0] = i;
        }
    }
    printf("English: %s (%d)\n", s[topper[0]].name, s[topper[0]].marks[0]);

    topper[1] = 0;
    for (i = 1; i < 3; i++)
    {
        if (s[i].marks[1] > s[topper[1]].marks[1])
        {
            topper[1] = i;
        }
    }
    printf("Hindi: %s (%d)\n", s[topper[1]].name, s[topper[1]].marks[1]);

    topper[2] = 0;
    for (i = 1; i < 3; i++)
    {
        if (s[i].marks[2] > s[topper[2]].marks[2])
        {
            topper[2] = i;
        }
    }
    printf("Maths: %s (%d)\n", s[topper[2]].name, s[topper[2]].marks[2]);

    topper[3] = 0;
    for (i = 1; i < 3; i++)
    {
        if (s[i].marks[3] > s[topper[3]].marks[3])
        {
            topper[3] = i;
        }
    }
    printf("Science: %s (%d)\n", s[topper[3]].name, s[topper[3]].marks[3]);

    topper[4] = 0;
    for (i = 1; i < 3; i++)
    {
        if (s[i].marks[4] > s[topper[4]].marks[4])
        {
            topper[4] = i;
        }
    }
    printf("Sst: %s (%d)\n", s[topper[4]].name, s[topper[4]].marks[4]);

    return 0;
}