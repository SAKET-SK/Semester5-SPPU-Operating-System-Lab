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
	char buf[100],buf1[100];
	int fd,fd1,words=0,lines=0,characters=0,len,i,count=0;
	char ch;
	FILE *fp;
	
	fd=open("fifo1",O_RDONLY);
	memset(buf,'\0',sizeof(buf));
	
	read(fd,buf,sizeof(buf));
	printf("\nMessage received\n");
	printf("%s",buf);
	close(fd);
	
	for(i=0;buf[i]!='\0';i++)
	{
		if(buf[i]==' ' || buf[i]=='\n' || buf[i]=='#')
			words++;
		if(buf[i]=='\n' || buf[i]=='#')
			lines++;
		if(buf[i]!=' ' && buf[i]!='\n' && buf[i]!='#')
			characters++;
	}
	
	printf("\nCounts are :\nCharacters: %d \nWords: %d \nLines: %d\n",characters,words,lines);
	
	fp=fopen("f.txt","w+");
	fprintf(fp,"\nCharacters: %d",characters);
	fprintf(fp,"\nWords: %d",words);
	fprintf(fp,"\nLines: %d\n",lines);
	fclose(fp);
	
	fp=fopen("f.txt","r");
	i=0;
	while((ch=fgetc(fp))!=EOF)
	{
		buf1[i]=ch;
		i++;
	}
	printf("\nBuffer contents");
	printf("\n%s",buf1);
	fclose(fp);
	unlink("fifo1");
	
	mkfifo("fifo2",0666);
	fd1=open("fifo2",O_WRONLY);
	write(fd1,buf1,sizeof(buf1));
	
	printf("\nMessage sent\n");
	close(fd1);
	return 0;
}





