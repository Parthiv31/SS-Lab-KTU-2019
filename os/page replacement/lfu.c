#include <stdio.h>

int main() {
   
    int n,rs[20],f,mf[20],recent[20]={0},r=0,c=0,i,j,k,min,pf=0;
    int count[20]={0},lc;
    printf("Enter length of reference string: ");
    scanf("%d",&n);
    printf("\nEnter reference string: ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);
    printf("\nEnter number of available frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        mf[i]=-1;
        recent[i]=0;
    }
    printf("\nPage\t\tFrames");
    for(i=0;i<n;i++){
        printf("\n%d\t\t\t",rs[i]);
        for(j=0;j<f;j++){
            if(rs[i]==mf[j]){
                recent[j]=r++;
                count[j]++;
                printf("No replacement");
                break;
            }
        }
        if(j==f){
            if(i<f){
                mf[c]=rs[i];
                count[c]++;
                recent[i]=r++;
                c=(c+1)%f;
            }
            else{
                min=0,lc=count[0];
                for(k=1;k<f;k++){
                    if( count[min]>count[k] && recent[min]>recent[k]){
                        min=k;
                        lc=count[k];
                    }
                }
                
                mf[min]=rs[i];
                count[min]=1;
                recent[min]=r++;
            }
            pf++;
            for(k=0;k<f;k++){
                printf("%d\t",mf[k]);
            }
            printf("Page fault %d",pf);
        }
        
        
    }
    printf("\nTotal page fault:\t%d",pf);
    return 0;
}