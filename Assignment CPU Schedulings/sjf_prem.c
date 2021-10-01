#include<stdio.h>
#include <string.h> 


struct process 
{
	    int pid;
	    int arrival_time;
	    int burst_time;
	    int start_time;
	    int completion_time;
	    int turnaround_time;
	    int waiting_time;
    
};

int main() 
{

    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    printf("Enter total number of processes   :   ");
    scanf("%d",&n);

    

    for(int i = 0; i < n; i++) 
    {
        printf("Enter arrival time of process  %d  ",i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time of process  %d  ",i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
     	printf("\n");
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) 
    {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) 
            {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mn) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) 
        {
            if(burst_remaining[idx] == p[idx].burst_time) 
            {
                	p[idx].start_time = current_time;
               
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
            
            if(burst_remaining[idx] == 0) 
            {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
               

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;
             
                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }

  

	    avg_turnaround_time = (float) total_turnaround_time / n;
	    avg_waiting_time = (float) total_waiting_time / n;
    
	       printf("\n\n");
	       printf("\nProcessID     ArrivalTime     BurstTime     Start Time      Completion Time    WaitingTime     TurnAroundTime");
	       printf("\n\n");

		    for(int i = 0; i < n; i++) 
		    {
		       
			 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid , p[i].arrival_time , p[i].burst_time , p[i].start_time ,p[i].completion_time, p[i].waiting_time,p[i].turnaround_time  );
		    }
		    printf("\nAverage Waiting Time =   %f  ",avg_waiting_time);
	    	    printf("\nAverage Turnaround Time =  %f  ",avg_turnaround_time);
	    
   
   	return 0;


}
