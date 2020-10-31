#include<pthread.h>
#include<stdio.h>
void *show_output(void *);
int main()
{
    pthread_t tid;
    char *str="This is Input String";
    pthread_create(&tid,NULL,show_output,(void *)str);
    pthread_join(tid,NULL);
    return 0;
}
void *show_output(void *args)
{
    char *str=(char*)args;
    printf("\nInput String is = %s",str);
    pthread_exit(NULL);
}
