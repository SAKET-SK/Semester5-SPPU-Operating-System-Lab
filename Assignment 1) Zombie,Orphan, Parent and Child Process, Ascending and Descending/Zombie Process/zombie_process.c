#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
void main()
{
    pid_t pid;
    int status;
    
    printf("Zombie Process Demonstration\n");
    printf("\nFrom Parent Process");
    pid=fork();
    if(pid==-1)
    {
        printf("\nProcess Creation Error");
    }
    else if(pid==0)
    {
        printf("\nI am Child Process ID = %d",getpid());
        printf("\nMy Parent Process ID = %d",getppid());
    }
    else
    {
        sleep(1);
        //system("ps");                     //abnormal temination of child. Parent doesnt care.   
        //wait(&status);
        system("ps");                       //child terminated normally
        printf("\nI am Parent Process ID = %d",getpid());
        printf("\nMy Child Process ID = %d",pid);
    }
}