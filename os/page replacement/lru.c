#include <stdio.h>

int main() {
    int n,rs[20],f,mf[20],recent[20]={0},r=0,c=0,i,j,k,min,pf=0;
    printf("Enter length of reference string: ");
    scanf("%d",&n);
    printf("Enter reference string: ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);
    printf("Enter number of available frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        mf[i]=-1;
        recent[i]=0;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(rs[i]==mf[j]){
                recent[j]=r++;
                break;
            }
        }
        if(j==f){
            if(i<f){
                mf[c++]=rs[i];
                recent[i]=r++;
            }
            else{
                min=0;
                for(k=1;k<f;k++){
                    if( recent[min]>recent[k]){
                        min=k;
                    }
                }
                mf[min]=rs[i];
                recent[min]=r++;
            }
            pf++;
            printf("\n");
            for(k=0;k<f;k++){
                printf("%d\t",mf[k]);
            }
            printf("Page fault %d\n",pf);
        }
        else{
            printf("\n");
            for(k=0;k<f;k++){
                printf("%d\t",mf[k]);
            }
            printf("\n");
        }
        
    }
    printf("Total page fault:\t%d",pf);
    return 0;
}