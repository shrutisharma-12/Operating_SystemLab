#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tat;
};

int main()
{
    struct process p[10];
    int n, i;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nEnter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);
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

    printf("\n%-10s %-15s %-15s %-15s\n", "Process", "Burst Time", "Waiting Time", "Turnaround Time");
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("P%-9d %-15d %-15d %-15d\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    printf("\nGantt Chart:\n\n");
    printf("0");

    int time = 0;
    for (i = 0; i < n; i++)
    {
        time = time + p[i].bt;
        printf(" ---- P%d ---- %d", p[i].pid, time);
    }

    return 0;
}