#include <stdio.h>

struct Process{
  int pid;
  int at;           //arrival time
  int bt;           //burst time
  int tt;           //turnaround time
  int st;           //service time
  int wt;           //wait time
  int ct;           //completion time
}p[10],temp;

int main() {
  
    int n;           // No of processes
    scanf("%d",&n);
    
    //Input process arrival, burst times 
    
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);
    }
    
    // Sorting processes according to arrival time
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n-i-1;j++){
        if(p[j].at>p[j+1].at){
          temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;
        }
      }
    }
    
    float totwttime=0,totttime=0;
    int t=0;
    
    // Calculate wait, turnaround and completion times
    
    for(int i=0;i<n;i++){
      p[i].st=t;
      t+=p[i].bt;
      p[i].wt=p[i].st-p[i].at;
      p[i].tt=p[i].wt+p[i].bt;
      p[i].ct=p[i].at+p[i].tt;
    
    }
  
    printf("PID\tBurst time\tWait Time\tTurn Around Time\tCompletion Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t %d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt,p[i].ct);
        totwttime+=p[i].wt;
        totttime+=p[i].tt;
    }
    printf("Average Wait: %.3f\n",totwttime/n);
    printf("Average Turn Around: %.3f",totttime/n);
    return 0;
}