#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,w;     //w is binary semphore; if this is true writer will perform write operation on file
int data = 0,rcount = 0;     //reader count and data count

void *writer(void *arg)
{
	  int f;
	  f = (*(*int) arg);
	  sem_wait(&w);    //if this sem_wait is performed then writer will be able to write into the file
	  data++;          //increase the data count after data is written
	  printf("Data writen by the writer %d is %d\n",f,data);
	  sleep(2);
	  sem_post(&w);     //After writing is complete then perform sem_post operation to signify end of wiriting operation
}


void *reader(void *arg)
{
	int f;
  	f = (*(int*)arg);
  	sem_wait(&mutex);     //mutual exclusion access gor read count
  	rcount = rcount + 1;  //increase the reader count after reader starts reading
  	if(rcount==1)
  	{
  		sem_wait(&w);  //if this sem_wait is performed then reader will be able to read from file
  	}
  	sem_post(&mutex);
  	printf("Data read by the reader %d is %d\n",f,data);
  	sleep(2);
  	sem_wait(&mutex);
  	rcount = rcount - 1;    //After reading is done, decrement the reader count
  	if(rcount==0)
  	{
  		sem_post(&w);   // If no readers i.e after reading is complete perform sem_post
  	}
  	sem_post(&mutex);     //end of mutual exclusion
}


int main()
{
	  int i; 
	  pthread_t rtid[5],wtid[5];     //reader and writer threads
	  sem_init(&mutex,0,1);          //mutex semaphore initialized
	  sem_init(&w,0,1);              //w semaphore for write control
	  for(i=0;i<=5;i++)
	  {
	    	pthread_create(&wtid[i],NULL,writer,(void *)&i);
	    	pthread_create(&rtid[i],NULL,reader,(void *)&i);
	  }
	  for(i=0;i<=5;i++)
	  {
	   	pthread_join(wtid[i],NULL);
	    	pthread_join(rtid[i],NULL);
	  }
	  return 0;
}
