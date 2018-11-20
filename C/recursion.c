#include<stdio.h>
long f(long x){
    //prlongf("siddhant");
    if (x==0){
        return 1;
    }

    return x*f(x-1);
}
void main(){
    long x ;
    printf("find the factorial so enter the number");
    scanf("%ld",&x);
    x=f(x);
    printf("%ld",x);

}