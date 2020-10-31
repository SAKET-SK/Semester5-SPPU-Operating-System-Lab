#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
void sort(int[],int);
void main()
{
    int a[10],n,i,b,S;
    pid_t pid;
    printf("\nEnter the number of elements to be sorted= ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter number %d: ",(i+1));
            scanf("%d",&a[i]);

    }
    
    pid=fork();
    if(pid==-1)
    {
        printf("\n Error in process creation");
    }
    else if(pid==0)
    {
        printf("\nValue received by child process pid= %d",pid);
        printf("\nThis CHILD process with id= %d",getpid());
        printf("\nMy PARENT process id is = %d",getppid());
        sort(a,n);
        for(i=0;i<n;i++)
        {
            printf("\nIN child= %d",a[i]);
        }
    }
    else
    {  
        wait(&S);
        printf("\n This is PARENT process with id= %d",getpid());
        printf("\n My CHILD process is= %d",pid);
        sort(a,n);
        for(i=n-1;i>=0;i--)
        printf("\n From parent = %d",a[i]);
    }
    


}

void sort(int a[],int n)
{
      int i,j,temp;
      for(i=1;i<n;i++)
      {
          temp=a[i];
          for(j=i-1;j>=0&&a[j]>temp;j--)
          a[j+1]=a[j];
          a[j+1]=temp;
          
       }
      
}
