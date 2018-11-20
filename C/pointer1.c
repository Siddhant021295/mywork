#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
char d[100];
char* super_reduced_string(char* s){
    
 int i=0;
 while(*s!='\0')
 {
     d[i]=*s;
     i++;
     s++;
 }
    d[i]='\0';

    return d;
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    super_reduced_string(s);
    char* result = super_reduced_string(s);
    printf("%s\n", result);
    return 0;
}
