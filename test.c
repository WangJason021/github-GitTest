#include<stdio.h>
#include<string.h>
typedef struct{
        int a;
        char b;
}MyStruct;

int main(){

    MyStruct m1;
    m1.a = 50;
    m1.b = 'C';
    printf("%d\n",m1.a);
    printf("%d\n",m1.b);
    memset(&m1, 0, sizeof(MyStruct));
    
    printf("%d\n",m1.a);
    printf("%d\n",m1.b);
    return 0;
}