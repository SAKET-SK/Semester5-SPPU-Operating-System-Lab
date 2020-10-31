#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

void Bubblesort(int[],int);
void Insertionsort(int[],int);

void main()
{
    int a[10],n,i,b,S;
    pid_t pid;
    printf("\n Emter Number of values ---> ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("\n Enter a value ---> \n");
        scanf("%d",&a[i]);
    }
    
    pid=fork();
    if(pid==-1)
    {
        printf("\n error in process");
    }
    else if(pid==0)
    {
        printf("\n Value receivrd by child process pid=%d",pid);
        printf("\n This child process with id=%d",getpid());
        printf("\nMy process id is =%d",getppid());
        Bubblesort(a,n);
        for(i=0;i<n;i++)
        {
            printf("\nIN child=%d",a[i]);
        }
    }
    else
    {  
        wait(&S);
        printf("\n This is parent process with id=%d",getpid());
        printf("\n My Child process is=%d",pid);
        Insertionsort(a,n);
        for(i=n-1;i>=0;i--)
        printf("\n From parent =%d",a[i]);
    }
    


}

void Bubblesort(int a[],int n)
{
      int i,j,temp;
      for(i=0;i<=n;i++)
      {
          for(j=i+1;j<=n-1;j++)
          {
              if(a[i]>a[j])
              {
                  temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
              }
          }
      }

}

void Insertionsort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		int value = a[i];
		int num = i;
		while( num>0 && a[num-1]>value)
		{
			a[num] = a[num-1];
			num--;
		}
		a[num] = value ;
	}
}
