#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int p[2],p1[2];
	pid_t pid;
	FILE *fp;
	char buffer[10];
	char str[]="hello.txt";
	pipe(p);
	pipe(p1);
	
	pid=fork();
	if(pid==0)
	{
		close(p[0]);
		write(p[1],str,sizeof(str));
		close(p[1]);
		close(p1[1]);
		printf("\n accepted contents are::");
		while(read(p1[0],buffer,sizeof(buffer)))
			{
				printf("%s",buffer);
				
			}
			close(p1[1]);
	}
	else
	{
		close(p[1]);
		read(p[0],buffer,sizeof(buffer));
		printf("\n accpected value is %s",buffer);
		close(p[0]);
		fp=fopen(buffer,"r");
		close(p1[0]);
		while(fgets(buffer,sizeof(buffer),fp))
			{
				write(p1[1],buffer,sizeof(buffer));
			}	
			close(p1[1]);
			
	}
	
}
