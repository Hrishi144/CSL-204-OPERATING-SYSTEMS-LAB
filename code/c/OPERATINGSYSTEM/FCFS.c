#include<stdio.h>
void main(){
    int head_pos,a[30],n;
    printf("Enter the number of disk requests:");
    scanf("%d",&n);
    printf("Enter the head position:");
    scanf("%d",&head_pos);
    printf("Enter the requests:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int seek_time;
    head_pos=a[0];
    printf("FIRST COME FIRST SERVE DISK SHEDULING");
    for(int i=0;i<n;i++){
    int distance=(a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i]);
     seek_time+=distance;
    }
    printf("\nThe total seek time is %d",seek_time);
}