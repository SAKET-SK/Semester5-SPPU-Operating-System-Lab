#include <stdio.h>

int main(int argc,char *argv[]){
	int array2[15];
	int noOfElements = argc; 
	printf("Into the second code\nargc value is %d\n",argc);
	for(int i = 0; i < noOfElements;i++){
		array2[i] = atoi(argv[i]);
		printf("%d\n",array2[i]);
	}
	int low = 0,mid, high = noOfElements;
	
	int temp;
	printf("Enter the number to be searched  ::\n");
	scanf("%d",&temp);
	
	while(low <= high){
		mid = low + (high-low)/2;
		if(array2[mid] == temp){
			printf("The number %d is at position %d!\n",temp,mid+1);
			break;
		}
		else if (array2[mid] > temp){
			high = mid-1;
			continue;
		}
		else{
			low = mid+1;
			continue;
		}
	}
	if(low > high){
		printf("Not found");
	}
	 
}

