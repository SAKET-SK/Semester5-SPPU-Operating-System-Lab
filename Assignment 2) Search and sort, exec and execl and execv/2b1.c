#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/types.h>

void bubbleSort(int array[],int);

int main(){
	int integerArray[15];
	int noOfElements;
	int pid;
	char *s[15],*str; //array of strings
	printf("Enter the no. of elements in the array :: ");
	scanf("%d",&noOfElements);
	printf("\n");
	
	printf("Enter the elements of array :: \n");
	for(int i = 0; i< noOfElements; i++){
		scanf("%d",&integerArray[i]);
	}
	
	printf("Accepted the array of numbers\n\n");
	printf("Now invoking fork\n\n");
	
	pid = fork();
	
	if(pid != 0){
		//parent process is invoked
		printf("Into the parent process\n");
		printf("Sorting the array\n");
		bubbleSort(integerArray,noOfElements);
		printf("The array is sorted\n");
		printf("\nParent sleeping to invoke child process\n");
		sleep(15);
		printf("Parent woke up\n");
		printf("The parent is exiting\n");
	}
	else if (pid == 0){
		printf("Into the child process\n");
		printf("Converting the array to the string\n");
				
		for(int j = 0 ; j<noOfElements; j++){
			printf("%d\n",integerArray[j]);
			sprintf(str,"%d",integerArray[j]);
			s[j] = malloc(sizeof(str));
			strcpy(s[j],str);
		}
		printf("Invoking another program\n");
		execve("./2b2",s,NULL);
		printf("Returned to child process\nChild exiting\n");
	}
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int array[],int n){
	int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (array[j] > array[j+1]) 
              swap(&array[j], &array[j+1]); 
}