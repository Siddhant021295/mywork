#include<stdio.h>
void siddhant(int x ,int y,int *s,int *d){
    *s=x+y;
    *d=x-y;

}
void main(){
    int x=20,y=10,s,d;
    siddhant(x,y,&s,&d);
    printf("%d , %d",s,d);
}