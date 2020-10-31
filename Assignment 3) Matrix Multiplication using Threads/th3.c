#include<pthread.h>
#include<stdio.h>
void *show_output(void *);
int main()
{
    pthread_t tid;
    int value;
    printf("\nEnter element :- ");
    scanf("%d",&value);
    pthread_create(&tid,NULL,show_output,(void *)&value);
    pthread_join(tid,(void *)&value);
    printf("\nReturned element from thread = %d",value);
    return 0;
}
void *show_output(void *args)
{
    int n = *(int *)args;
    printf("\nAccepted element from main = %d",n);
    n=n+1;
    pthread_exit((void *)n);
}
