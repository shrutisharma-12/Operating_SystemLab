#include <stdio.h>

struct process
{
    int pid, pr, bt, wt, tat;
};
int main()
{
    struct process p[10], temp;
    int n, i, j, minIndex;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for P1: ");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i);
        scanf("%d", &p[i].bt);
    }

    printf("Enter priority for P[%d]\n", i);
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i);
        scanf("%d", &p[i].pr);
        p[i].pid = i;
    }
    // Sorting based on priority (lower value = higher priority)
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j].pr < p[minIndex].pr)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            temp = p[i];
            p[i] = p[minIndex];
            p[minIndex] = temp;
        }
    }
    p[0].wt = 0;

    for (i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
        avg_wt = avg_wt + p[i].wt;
        avg_tat = avg_tat + p[i].tat;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
    }
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    printf("\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f", avg_tat);
    return 0;
}