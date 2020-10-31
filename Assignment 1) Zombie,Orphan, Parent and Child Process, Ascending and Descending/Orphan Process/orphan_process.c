#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
void main()
{
    pid_t pid;
    printf("Orphan Process Demonstration\n");
    pid=fork();
    if(pid==-1)
    {
        printf("\nProcess Creation Error");
    }
    else if(pid==0)
    {
        sleep(3);
        printf("\nI am Child Process ID = %d",getpid());
        printf("\nMy Parent Process ID = %d",getppid());
    }
    else
    {
        printf("\nI am Parent Process ID = %d",getpid());
        printf("\nMy Child Process ID = %d",pid);
    }
}