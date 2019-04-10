#include<stdio.h>
#include<conio.h>
#include<unistd.h>
struct scheduling
{
       int p,arr,brt,rnt,tempp,pr;
};

void sortarrival(struct scheduling a[],int pro)
{
       int i,j;
       struct scheduling temp;
       int y;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].arr > a[j].arr)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
                    
              }
               
       }
       return;
}
//for prioirity scheduling

void sortpriority(struct scheduling c[],int pro)
{
       int i,j;
       struct scheduling temp;
       int y;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(c[i].pr > c[j].pr)
                     {
                           temp = c[i];
                           c[i] = c[j];
                           c[j] = temp;
                     }
                    
              }
               
       }
       return;
}

void priorityy(struct scheduling c[],int u)
{	int i,time1;
	
	printf("\n***************************************\n");
       printf("  Priority Scheduling(non-premptive)   ");
       printf("\n***************************************\n\n");

	for(i=0;i<u;i++)
	{
		c[i].p = i;
	}

       printf("Gantt Chart:\n");
	sortarrival(c,u);
	time1=c[0].arr;
	int z=c[0].arr;
	printf("%d",time1);
       for(i=0;i<u;i++)
    {
    	time1=time1+c[i].brt;
    	printf(" -> [P%d] <- %d",c[i].p,time1);
    	
    	break;
	}
	
	
	sortpriority(c,u);
	
	
	
       //printf("%d",time1);
       for(i=0;i<u;i++)
    {	if(z==c[i].arr)
    	{
    		continue;
		}
    	time1=time1+c[i].brt;
    	printf(" -> [P%d] <- %d",c[i].p,time1);
	}
	
	
}



void fcfs(struct scheduling b[],int k)
{
	
	int i,time;
	printf("\n***************************************\n");
       printf("           First Come First Serve        ");
       printf("\n***************************************\n\n");
	for(i=0;i<k;i++)
	{
	b[i].p = i;
	}
	sortarrival(b,k);
	time=b[0].arr;
	
       printf("Gantt Chart:\n");
       printf("%d",time);
    for(i=0;i<k;i++)
    {
    	time=time+b[i].brt;
    	printf(" -> [P%d] <- %d",b[i].p,time);
	}
}


void roundrobin(struct scheduling a[],int pro){
	int i,j,time,remain,flag=0,ts=4;
       
       
       remain=pro;
       for(i=0;i<pro;i++)
       {
              a[i].p = i;
              a[i].rnt = a[i].brt;
       }
       sortarrival(a,pro);
       printf("\n***************************************\n");
       printf("           Round Robin Algorithm         ");
       printf("\n***************************************\n\n");
       printf("Gantt Chart:\n\n");
       time=a[0].arr;
       printf("%d",time);
       for(time=a[0].arr,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" -> [P%d] <- %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf(" -> [P%d] <- %d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     flag=0;
              }
              if(i==pro-1)
                     i=0;
              else if(a[i+1].arr <= time)
                     i++;
              else
                     i=0;
}
}
int main()
{
	int n,i;
	struct scheduling x[100],y[100];
	printf("Note:\n1-The CPU should never be idle.\n2-The first round robin is of 4 seconds.\n3-Between the processes there is a round robin of 10 seconds.\n\n");
	printf("Enter total number of process:");
	scanf("%d",&n);
	printf("\nEnter Arrival Time,Burst Time and Priority of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\n",i);
		printf("Arrival Time:");
		scanf("%d",&x[i].arr);
		printf("Burst Time:");
		scanf("%d",&x[i].brt);
		printf("Priority:");
		scanf("%d",&x[i].pr);
	
		//p[i]=i+1;
	}
	
	printf("Highest prioirty queue-(0-3)\n");
	printf("Medium proiority queue-(4-6)\n");
	printf("Lowest priority queue-(7-9)\n\n");
	printf("Processes assigned to different queues are:\n\n");
	for(i=0;i<n;i++)
	{
		if(x[i].pr==0 || x[i].pr==1 || x[i].pr==2 || x[i].pr==3)
		{
			printf("Queue 1 has process- P[%d]\n",i);
		}
	}
	for(i=0;i<n;i++)
	{
		if(x[i].pr==4 || x[i].pr==5 || x[i].pr==6)
		{
			printf("Queue 2 has process- P[%d]\n",i);
		}
	}
	for(i=0;i<n;i++)
	{
		if(x[i].pr==7 || x[i].pr==8 || x[i].pr==9)
		{    
			printf("Queue 3 has process- P[%d]\n",i);
		}
	}
	
	
	
	

	//roundrobin(x,n);
	//priorityy(x,n);
	
	roundrobin(x,n);
	sleep(10);
	
	priorityy(x,n);
	sleep(10);
	
	fcfs(x,n);
	
	
	
	return(0);

}

