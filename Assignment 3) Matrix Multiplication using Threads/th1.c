#include<pthread.h>
#include<stdio.h>
void *show_output(void *);
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,show_output,NULL);
    pthread_join(tid,NULL);
    return 0;
}
void *show_output(void *args)
{
    printf("This is Output");
    pthread_exit(NULL);
}
