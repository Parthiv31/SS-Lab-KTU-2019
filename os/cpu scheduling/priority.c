#include <stdio.h>

struct Process {
    int pid;
    int pt; // priority, lower number higher priority here
    int at; // arrival time
    int bt; // burst time
    int tt; // turnaround time
    int wt; // wait time
    int st; // service time
    int ct; // completion time
    int flag; //flag to check completion
} p[10], temp;


int findProcess(int n,int t){
    int ind;
    for(int i=0;i<n;i++){
        if(p[i].flag==0){
            ind=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(p[i].flag==0){
            if(p[i].at<=t && p[i].pt<=p[ind].pt){
                if(p[i].pt==p[ind].pt && p[i].at>p[ind].at){
                    continue;
                }
                else ind=i;
            }
        }
    }
    return ind;
}

int main() {
    int n; // No of processes
    scanf("%d", &n);
    // Input process arrival and burst times 
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &p[i].pid,&p[i].pt, &p[i].bt, &p[i].at);
        p[i].flag=0;
    }

    // Sorting processes according to arrival time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    
    float totwttime = 0, totttime = 0;
    int t = p[0].at;

    // Calculate wait, turnaround, and completion times

    for (int i = 0; i < n; i++) {
        int ind=findProcess(n,t);
         printf("%d\n",ind);
        p[ind].st=t;
        t+=p[ind].bt;
        p[ind].wt = p[ind].st - p[ind].at;
        p[ind].tt = p[ind].wt + p[ind].bt;
        p[ind].ct = p[ind].tt + p[ind].at;
        p[ind].flag=1;                       //Setting process as completed
    }

    printf("PID\tBurst time\tWait Time\tTurn Around Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt, p[i].ct);
        totwttime += p[i].wt;
        totttime += p[i].tt;
    }
    printf("Average Wait: %.3f\n", totwttime / n);
    printf("Average Turn Around: %.3f", totttime / n);
    return 0;
}
