#include <stdio.h>

// Input : blockSize[]   = {100, 500, 200, 300, 600};
//         processSize[] = {212, 417, 112, 426};
// Output:
// Process No.    Process Size    Block no.
//  1        212        4
//  2        417        2
//  3        112        3
//  4        426        5

int main() {
   int b[10],p[10],pa[10],bn,pn;
   printf("Enter number of blocks: ");
   scanf("%d",&bn);
   printf("\nEnter block sizes: ");
   for(int i=0;i<bn;i++)
        scanf("%d",&b[i]);
        
   printf("\nEnter number of processes: ");
   scanf("%d",&pn);
   printf("\nEnter process sizes: ");
   for(int i=0;i<pn;i++)    
        scanf("%d",&p[i]);
        
    for(int i=0;i<pn;i++){
        int bestIndex=-1;
        for(int j=0;j<bn;j++){
            if(p[i]<=b[j]){
                if(bestIndex==-1 || b[j]<b[bestIndex]){
                    bestIndex=j;
                }
            }
        }
        pa[i]=bestIndex;
        if(bestIndex!=-1)
            b[bestIndex]-=p[i];
    }

    printf("\nProcess No.\tSize\tBlock No.\n");
    for(int i=0;i<pn;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(pa[i]!=-1){
            printf("%d\n",pa[i]+1);
        }
        else {
            printf("Not allocated\n");
        }
    }
    
    return 0;
}

