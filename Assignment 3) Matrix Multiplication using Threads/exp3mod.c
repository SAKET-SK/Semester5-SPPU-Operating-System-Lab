#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
void *multi (void *);
struct mult{
    int num1,num2;
};
int main ()
{
  pthread_t tid[30];
  int A[10][10],B[10][10],i,j,k,count,C[10][10]={0},m,n,m1,n1,value[50];
  struct mult nu;
  int res1,res2;
  printf ("\nenter rows and columns of first matrix \n");
  scanf ("%d%d", &m,&n);
  printf("\n enter numbers of first matrix\n");
  for(i=0;i<m;i++)
  {
      for(j=0;j<n;j++)
      {
          scanf("%d",&A[i][j]);
      }
  }
   printf ("\nenter rows and columns of second matrix \n");
  scanf ("%d%d", &m1,&n1);
  printf("\n enter numbers of second matrix\n");
  for(i=0;i<m1;i++)
  {
      for(j=0;j<n1;j++)
      {
          scanf("%d",&B[i][j]);
      }
  }
//   if(n==m1)
//   {
      count=0;
      for(i=0;i<m;i++)
      {
          for(j=0;j<n1;j++)
          {
              for(k=0;k<n;k++)
              {
                  nu.num1=A[i][k];
                  nu.num2=B[k][j];
                  pthread_create(&tid[count],NULL,multi,(void*)&nu);
                  sleep(1);
                  count++;
              }
          }
      }
//  }
//   else
//   {
//       printf("\nmultiplication invalid");
//   }
  int x=0;
   count=0;
      for(i=0;i<m;i++)
      {
          for(j=0;j<n1;j++)
          {
              for(k=0;k<n;k++)
              {
                 pthread_join(tid[count],(void *)&value[count]);
                  x=x+value[count];
                  count++;
              }
              C[i][j]=x;
              x=0;
          }
      }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("%d\t",C[i][j]);
        }
    }
}

void *multi(void *argp)
{
    int x;
    struct mult *obj;
    obj=( struct mult*)argp;
    x=obj->num1*obj->num2;
    sleep(1);
    pthread_exit((void *)x);
}

