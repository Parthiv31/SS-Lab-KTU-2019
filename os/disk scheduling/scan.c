#include <stdio.h>

int main() {
   
    int n,rs[20],h,total=0,sequence[20],size,dir,current,c=0;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    
    printf("\nEnter request sequence : ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);
        
    printf("\nEnter initial head position: ");
    scanf("%d",&h);
    
    printf("\nEnter disk size: ");
    scanf("%d",&size);
    
    printf("\nEnter disk movement direction as 1( for high) / 0(for low): ");
    scanf("%d",&dir);
    
    //sorting
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(rs[j]>rs[j+1]){
                int t=rs[j];
                rs[j]=rs[j+1];
                rs[j+1]=t;
            }
        }
    }
    
    int left,right;
    for(int i=0;i<n;i++){
        if(rs[i]>=h){
            right=i;
            left=i-1;
            break;
        }
    }
    if(dir==1){
        
        for(int i=right;i<n;i++){
           current=rs[i];
           sequence[c++]=current;
        }
        
        for(int i=left;i>=0;i--){
            current=rs[i];
            sequence[c++]=current;
        }
        printf("\nSeek sequence: ");
        for(int i=0;i<n;i++){
            if(i!=n-1)printf("%d -> ",sequence[i]);
            else
                printf("%d",sequence[i]);
        }
        total=size-h+size-rs[0];
    }
    else{
       
        for(int i=left;i>=0;i--){

           current=rs[i];
           sequence[c++]=current;
        }
        for(int i=right;i<n;i++){
            current=rs[i];
            sequence[c++]=current;
        }
        printf("\nSeek sequence: ");
        for(int i=0;i<n;i++){
            if(i!=n-1)printf("%d -> ",sequence[i]);
            else
                printf("%d",sequence[i]);
        }
        total=h+rs[n-1];
    }

    printf("\nTotal head movement:\t%d",total);
    return 0;
}