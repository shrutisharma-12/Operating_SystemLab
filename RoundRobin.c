#include<stdio.h>
struct process
{
    int pid, bt, wt, tat,r_bt;
} p[10], temp;
int main()
{
    int n, time=0, quantum;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        p[i].pid = i+1;
        printf("Enter burst time for P[%d]: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].r_bt = p[i].bt;
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    while(1){
        int finish=1;
        for(int i=0;i<n;i++){
            if(p[i].r_bt > 0){
                finish=0;
                if(p[i].r_bt > quantum){
                    time += quantum;
                    p[i].r_bt -= quantum;
                }
                else{
                    time += p[i].r_bt;
                    p[i].wt = time - p[i].bt;
                    p[i].tat = time;
                    p[i].r_bt = 0;
                }
            }
        }
        if(finish) break;
    }
    for(int i=0;i<n;i++){
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    printf("Average waiting time: %.2f\n", avg_wt/n);
    printf("Average turnaround time: %.2f\n", avg_tat/n);
    return 0;
}
