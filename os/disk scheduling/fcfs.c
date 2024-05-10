#include <stdio.h>

int main() {
   
    int n,rs[20],h,total=0;
    int count[20]={0},lc;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("\nEnter request sequence : ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);
    printf("\nEnter initial head position: ");
    scanf("%d",&h);
    
     printf("\nSeek sequence: ");
     printf("%d -> ",h);
    int current=h;
    for(int i=0;i<n;i++){
       total+=abs(current-rs[i]);
       if(i!=n-1){
           printf("%d -> ",rs[i]);
       }
       else {
           printf("%d",rs[i]);
       }
       current=rs[i];
    }
    
    printf("\nTotal head movement:\t%d",total);
    return 0;
}