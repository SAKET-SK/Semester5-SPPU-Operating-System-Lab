#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int p[2],p1[2];
	char buffer[80];
	char str[]="ass9.c";
	pid_t pid;
	FILE *fp;
	pipe(p);
	pipe(p1);
	
	pid=fork();
	if(pid==0)
	{
		close(p[0]);
		write(p[1],str,sizeof(str));
		close(p[1]);
		close(p1[1]);
		printf("\nAccepted contents are: ");
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
		printf("\nAccepted value is: %s ",buffer);	
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



/*Output:

samiksha@Samiksha:~$ gcc ass9.c
samiksha@Samiksha:~$ ./a.out


Accepted contents are: #include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int p[2],p1[2];
	char buffer[80];
	char str[]="ass9.c";
	pid_t pid;
	FILE *fp;
	pipe(p);
	pipe(p1);
	
	pid=fork();
	if(pid==-1)
        	printf("\n Error in process creation");
    	else if(pid==0)
Accepted value is: ass9.c 	{
		close(p[0]);
		write(p[1],str,sizeof(str));
		close(p[1]);
		close(p1[1]);
		printf("\nAccepted contents are: ");
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
		printf("\nAccepted value is: %s ",buffer);	
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
samiksha@Samiksha:~$ 
*/
