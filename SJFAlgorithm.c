#include <stdio.h>
struct process
{
    int pid, bt, wt, tat;
} p[10], temp;
int main()
{
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time of processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i);
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
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
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }
   // avg_wt /= n;
    //avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}