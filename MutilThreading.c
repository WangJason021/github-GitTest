#include<stdio.h>
#include<string.h>
#include<pthread.h>

typedef struct{
        int a;
        char b;
}MyStruct;

typedef unsigned char uint8;

pthread_mutex_t lock1;

int s = 0;

void *plus(void *args)
{
    pthread_mutex_lock(&lock1);
    char *name = (char *)args;   
    for(int i = 0; i < 100000; i++)
    {
        s++;
    }
    pthread_mutex_unlock(&lock1);
    printf("%s end!\n",name);
    
    return NULL;
}


int main(){
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
    pthread_t th5;
    pthread_t th6;

    pthread_mutex_init(&lock1, NULL);

    pthread_create(&th1, NULL, plus, (void *)"th1");
    pthread_create(&th2, NULL, plus, (void *)"th2");
    pthread_create(&th3, NULL, plus, (void *)"th3");
    pthread_create(&th4, NULL, plus, (void *)"th4");
    pthread_create(&th5, NULL, plus, (void *)"th5");
    pthread_create(&th6, NULL, plus, (void *)"th6");

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    pthread_join(th4,NULL);
    pthread_join(th5,NULL);
    pthread_join(th6,NULL);

    printf("%d",s);
    return 0;
}