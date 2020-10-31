#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int p[2],p1[2];
  pid_t pid;
  FILE *fp;
  char buffer [80];
  char str[]="main.c";
  pipe(p);
  pipe(p1);

  pid=fork();
  if(pid==0)
  {
    close(p[0]);
    write(p[1],str,sizeof(str));
    close(p[1]);
    close(p1[1]);
    printf("\nAccepted contents are:");
    while(read(p1[0],buffer,sizeof(buffer)))
    {
      printf("%s",buffer);
    }
    close(p1[1]);
  }

  else
  {
    close(p1[1]);
    read(p[0],buffer,sizeof(buffer));
    printf("\nAccepted Value is:");
    close(p[0]);
    fp=fopen(buffer,"r");
    close(p1[0]);
    while(fgets(buffer,sizeof(buffer),fp))
    {
      write(p[1],buffer,sizeof(buffer));
    }
    close(p1[1]);
  }
  return 0;
}
