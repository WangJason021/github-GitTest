#include<stdio.h>
#ifndef X
#define X 5
#endif

int main(){
    #if (defined X)
    printf("1234");
    #endif
    return 0;
}