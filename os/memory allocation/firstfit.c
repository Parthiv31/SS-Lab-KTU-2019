#include <stdio.h>

// Input : blockSize[]   = {100, 500, 200, 300, 600};
//         processSize[] = {212, 417, 112, 426};
// Output:
// Process No.    Process Size    Block no.
//    1               212            2
//    2               417            5
//    3               112            2
//    4               426        Not Allocated

int main() {
    int b[10],p[10],bn,pn;
    int pa[10];

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
        pa[i]=-1;
    }

    for(int i=0;i<pn;i++){
        for(int j=0;j<bn;j++){
            if(p[i]<=b[j] ){
                pa[i]=j;
                b[j]-=p[i];

                break;
            }
        }
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

