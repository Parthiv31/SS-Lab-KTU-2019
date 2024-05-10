
#include <stdio.h>

int main() {

    int n,rs[20],f,mf[10],i,j,k,c=0,pf=0;
    printf("Enter length of reference string of requests: ");
    scanf("%d",&n);
    printf("\nEnter reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("\nEnter number of frames available: ");
    scanf("%d",&f);
    
    for(i=0;i<f;i++)mf[i]=-1;
    
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(rs[i]==mf[j]){
                break;
            }
        }
        if(j==f){
            mf[c]=rs[i];
            c=(c+1)%f;
            pf++;
            printf("\n");
            for(k=0;k<f;k++){
                printf("%d\t",mf[k]);
            }
            printf("Page fault %d",pf);
        }
        else{
            printf("\n");
            for(k=0;k<f;k++){
                printf("%d\t",mf[k]);
            }
        }  
            
        
    }
    printf("\nTotal Page faults:\t%d",pf);

    return 0;
}