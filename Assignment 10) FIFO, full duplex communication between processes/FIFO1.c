#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main()
{
	char buf[100],buf1[100],str;
	int fd,fd1,i=0;
	
	//memset(buf1,'\0',sizeof(buf1));
	printf("\nEnter the string : \n");
	while((str=getchar())!='#')
		buf[i++]=str;
	puts(buf);
	
	mkfifo("fifo1",0666);
	fd=open("fifo1",O_WRONLY);
	write(fd,buf,sizeof(buf));
	printf("\nMessage sent");
	close(fd);
	
	fd1=open("fifo2",O_RDONLY);
	read(fd1,buf1,sizeof(buf1));
	printf("\n\nMessage received");
	printf("%s",buf1);
	close(fd1);
	return 0;
}



