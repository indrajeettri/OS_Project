#include<stdio.h>
#include<stdlib.h>
void clear_screen();

void Process(int time_quantum)
{
    int i,j,n,time,remain,flag=0;
      int wait_time=0,turnaround_time=0,ArivalTime[10],BurstTime[10],rt[10];     
    printf("\n\nEnter Total Process:\t ");
    scanf("%d",&n);
    clear_screen();   
      remain=n;
      for(int i=0;i<n;i++)
      {
            printf("\nEnter Arrival Time for Process Number %d :",i+1);
			scanf("%d",&ArivalTime[i]);
        //printf("------------------------------------------");
        printf("\nEnter CPU Burst Time for Process Number %d   :",i+1);
		scanf("%d",&BurstTime[i]);
        printf("------------------------------------------\n");
            rt[i]=BurstTime[i];
      }
    clear_screen();
    printf("\n\n\t+++++++++++++++++++++++++++++ Result  ++++++++++++++++++++++++++++++\n\n");
    printf("\n\nProcess\t|Turnaround Time|Waiting Time");
    printf("\n-------\t---------------\t------------\n\n");
      for(time=0,i=0;remain!=0;)
      {
            if(rt[i]<=time_quantum && rt[i]>0)
           {
                  time+=rt[i];
                  rt[i]=0;
                  flag=1;
            }
            else if(rt[i]>0)
            {
                  rt[i]-=time_quantum;
                  time+=time_quantum;
            }
            if(rt[i]==0 && flag==1)
            {
                  remain--;
                  printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-ArivalTime[i],time-ArivalTime[i]-BurstTime[i]);
                  wait_time+=time-ArivalTime[i]-BurstTime[i];
                  turnaround_time+=time-ArivalTime[i];
                  flag=0;
            }
            if(i==n-1)
                  i=0;
            else if(ArivalTime[i+1]<=time)
                  i++;
            else
                  i=0;
      }
      printf("\n Total  Waiting Time= %f\n",wait_time*1.0);
      printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
      printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}

void clear_screen()
{
    system("clear");
}

int main()
{
 
 
  //int TimeQuantum[2] = {6,10};
  clear_screen();
  int n;
  printf("\nEnter The Number Of Time Quanta You Want : ");
  scanf("%d", &n);
  int *TimeQuantum = (int*) malloc(n * sizeof(int)); //Dynamically Declared Array To Store The Quantum Time Dynamically
  for( int i = 0;i<n;i++)
  {
    printf("\nEnter Time Quantum for Process_Set-->%d :",i+1);
	scanf("%d", TimeQuantum+i);
  }
  int max = *(TimeQuantum+0);
  for(int i = 0;i<n; i++)
  {
    Process(*(TimeQuantum+i));
  }
  return 0;
}

