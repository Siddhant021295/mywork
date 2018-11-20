#include<stdio.h>
void sort (int x , int m[])
{
    int i,j,t;
    for(i=0;i<x-1;i++){
        for(j=1;j<=x-i;j++){
            if(m[j-1]>=m[j]){
                t=m[j-1];
                m[j-1]=m[j];
                m[j]=t;
            }
        }
    }


}
void main(){
    int x,m[5],i;
    scanf("%d",&x);
    printf("enter the array");
    for (int i =0;i<x;i++){
        scanf("%d",&m[i]);

    }
    sort(x,m);
    for(i=0;i<x;i++){
        printf("%d  ",m[i]);
    }
}