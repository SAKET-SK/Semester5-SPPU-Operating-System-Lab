#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>    //Header for semaphores i.e empty,full,etc.
#include<pthread.h>

sem_t f,s,e;             //f-> full, s->main semaphore , e->empty
pthread_mutex_t mutex;    //mutual exclusion
int arr[5];             //buffer to store values

//in and out pointing to first location as no element is present
int in=0;
int out=0;
//integers value used as an index

void *producer(void *data)    //producer
{
	int i,n,value;    //value for stored value
	value=(int) data;  //typecasting
	for(i=0;i<4;i++)   // 3 producers * 4 items -> 12
	{
		sem_wait(&e);      //decrements the value signifying no of empty places
		sem_wait(&s);      //decrements the value of main semaphore to 0, by default 1
		
		n=value;           //put the value to be placed in buffer in n
		arr[in]=n;    //put the value in n in the buffer
		printf("\nProducer %d produced value %d at buffer location %d",i,arr[in],in);
		in=(in+1)%5;
		
		sem_post(&s);
		sem_post(&f);
		sleep(2);
	}
}

void *consumer(void *data)    //consumer
{
	int i,n,x;
	do
	{
		sem_wait(&f);
		sem_wait(&s);
		
		n=arr[out];     //Extract the value from buffer
		printf("\n\tConsumer consumed value %d from buffer location %d",n,out);
		out=(out+1)%5;
		
		sem_post(&s);
		sem_post(&e);
		sleep(2);
		sem_getvalue(&e,&x);
	}while(x!=5);
}

int main()
{
	pthread_t tid[5],tid1;
	int i;
	sem_init(&f,0,0);     //initializing full semaphore
	sem_init(&e,0,5);     //initializing empty semaphore
	sem_init(&s,0,1);     //initializing main semaphores
	for(i=0;i<4;i++)
	{
		pthread_create(&tid[i],NULL,producer,(void *) i);
	}
	pthread_create(&tid1,NULL,consumer,NULL);
	for(i=0;i<4;i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_join(tid1,NULL);
	return 0;
}











































		
