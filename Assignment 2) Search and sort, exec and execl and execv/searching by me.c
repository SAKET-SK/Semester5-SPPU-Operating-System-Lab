#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{

 int i,j,c,ele;
 int arr[argc];

 for(i=0;i<argc-1;i++)
 
 {
  int n=atoi(argv[i]);
  arr[i]=n;
 }

 ele=atoi(argv[i]);
 i=0;
 j=argc-1;
 c=(i+j)/2;

 while(ele!=arr[c] && i<=j)
 {
  if(arr[c]<ele)
   i=c+1;
  else
   j=c-1;
  c=(i+j)/2;
   
 }

 if(i<=j)
  printf("Elemets  found");
 else 
  printf("Not found");



}
