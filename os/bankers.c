
#include <stdio.h>
#include <stdbool.h>
bool incomplete(bool f[],int m){
    for(int i=0;i<m;i++){
        if(!f[i])return 1;
    }
    return 0;
}


int main() {
 
    int n,m;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&m);
    int max[n][m],need[n][m],alloc[n][m],avail[m],work[m],safe[n]
    ,ss=0;
    bool f[m];
    for(int i=0;i<m;i++)f[i]=false;
    printf("\nGive available resources' counts: ");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
        work[i]=avail[i];
    }
    
    
    printf("Give each  processes' maximum demand for resources:- ");
    for(int i=0;i<n;i++){
        printf("\nP%d: ",i);
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nGive each process' allocated resource counts :- ");
    for(int i=0;i<n;i++){
        printf("\nP%d: ",i);
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    int i=0;
    while(true){
        if(!f[i]){
            bool flag=1;
            for(int j=0;j<m;j++){
                if(need[i][j]>work[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                for(int j=0;j<m;j++){
                    work[j]+=need[i][j];
                }
                f[i]=1;
                safe[ss++]=i;
            }
        }
        i=(i+1)%n;
        if(!incomplete(f,m))break;
    }
    printf("\n");
    for(int i=0;i<n;i++)printf("P%d ",safe[i]);
    

    return 0;
}