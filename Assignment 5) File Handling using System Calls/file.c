#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#define SRC_FILE_NAME "SRC1.txt"
#define DEST_FILE_NAME "DEST1.txt"

typedef struct Employee
{
	int Id;
	char Name[10];

}Employee;

int main()
{
	Employee e;
	char c;
	int in,out,d,flag=0,count,ch,size;
	do
	{
		flag=0;
		printf("\nOptions:\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			if((in = open(SRC_FILE_NAME, O_WRONLY|O_APPEND|O_CREAT, 0666)) == -1)
			{
				printf("\nError in opening the file");
				exit(1);
			}
			else
			{
				printf("\nFile opened successfully");
				printf("\nEnter Id: ");
				scanf("%d",&e.Id);
				printf("Enter Name: ");
				scanf("%s",e.Name);
				write(in,&e,sizeof(Employee));
				close(in);
			}
			break;
			
		case 2:
			if((in = open(SRC_FILE_NAME, O_RDONLY)) == -1)
			{
				printf("\nError in opening the file");
				exit(1);
			}
			else
			{
				printf("\nFile opened successfully");
				
				printf("\nID \t Name\n");
				while(read(in,&e,sizeof(Employee)))
				{
					printf("%d\t%s\n",e.Id,e.Name);
				}
				close(in);
			}
			break;
			
		case 3:
			flag=0;
			in = open(SRC_FILE_NAME, O_RDONLY);
			if ((in = open(SRC_FILE_NAME, O_RDONLY)) == -1)
			{
				printf("\nError in opening file");
			}
			printf("\nSource file opened");
			printf("\nEnter Id to be searched: ");
			scanf("%d",&d);
			while(read(in,&e,sizeof(Employee)))
			{
				if(e.Id==d)
				{
					printf("\nRecord found");
					printf("\nId\tName\n");
					printf("%d\t%s",e.Id,e.Name);
					flag=1;
					break;
				}
			}
			if(flag!=1)
				printf("\nRecord not found in the file");
			
			break;
			
		case 4: 
			break;
		}
	}while(ch!=4);
}
