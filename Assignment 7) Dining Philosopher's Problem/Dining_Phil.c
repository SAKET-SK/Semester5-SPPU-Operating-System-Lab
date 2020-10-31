#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>             //for semaphore
#include<pthread.h>
#include<string.h>

sem_t sem_room;
sem_t sem_fork[5];          //No of resources

void eat(int n)            //shows which philosopher eats (consumes the resources)
{
	printf("Philosopher %d is eating\n",n);
}

void* philosopher (void* no)
{
	int n = *(int *)no;
	sem_wait(&sem_room);
	printf("Philosopher %d has entered the room\n",n);
	sem_wait(&sem_fork[n]);               //Left chopstick
	sem_wait(&sem_fork[(n+1)%5]);         //Right chopstick
	eat(n);                        //if both chopsticks got, then perform eat operation
	sleep(2);
	printf("Philosopher %d has finished his eating\n",n);
	sem_post(&sem_fork[(n+1)%5]);             //release right chopstick
	sem_post(&sem_fork[n]);                   //release left chopstick
	sem_post(&sem_room);                //once done eating, release the space for others
}

void main()
{
	int arr[10],i;
	pthread_t pt[10];
	void * th_res;
	sem_init(&sem_room,0,4);    //sem_room initialized with 4 i.e 0-1-2-3-4
	
	for(i=0;i<5;i++)
	{
		sem_init(&sem_fork[i],0,1);      //binary semaphore for resource status
	}
	
	for(i=0;i<5;i++)           //create thread
	{
		arr[i]=i;
		pthread_create(&pt[i],NULL,philosopher,(void*)&arr[i]);
	}
	
	for(i=0;i<5;i++)          //join threads
	{
		pthread_join(pt[i],NULL);
	}
}
