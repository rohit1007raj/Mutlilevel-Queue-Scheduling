#include<stdio.h>
#include<conio.h>
#include<unistd.h>
struct times
{
       int p,art,but,wtt,tat,rnt,tempp,pr;
};

void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       int y;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].art > a[j].art)
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

void sortart1(struct times c[],int pro)
{
       int i,j;
       struct times temp;
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

void priorityy(struct times c[],int u)
{	int i,time1;
	
	printf("\n\nProiority scheduling\n\n");

	for(i=0;i<u;i++)
	{
		c[i].p = i;
	}
	printf("\n***************************************\n");
       printf("Gantt Chart\n");
	sortart(c,u);
	time1=c[0].art;
	int z=c[0].art;
	printf("%d",time1);
       for(i=0;i<u;i++)
    {
    	time1=time1+c[i].but;
    	printf(" -> [P%d] <- %d",c[i].p,time1);
    	
    	break;
	}
	
	
	sortart1(c,u);
	
	
	
       //printf("%d",time1);
       for(i=0;i<u;i++)
    {	if(z==c[i].art)
    	{
    		continue;
		}
    	time1=time1+c[i].but;
    	printf(" -> [P%d] <- %d",c[i].p,time1);
	}
	
	
}



void fcfs(struct times b[],int k)
{
	
	int i,time;
	
	printf("\n\nFCFS Scheduling Algorithm\n");
	for(i=0;i<k;i++)
	{
	b[i].p = i;
	}
	sortart(b,k);
	time=b[0].art;
	printf("\n***************************************\n");
       printf("Gantt Chart\n");
       printf("%d",time);
       int count=5;
    for(i=0;i<k;i++)
    {
    	time=time+b[i].but;
    	count=count+3;
    	printf(" -> [P%d] <- %d",b[i].p,time);
    	if(count>=10)
    	{
    		return;
		}
	}
}


void roundrobin(struct times a[],int pro){
	int i,j,time,remain,flag=0,ts=4;
       
       float avgwt=0,avgtt=0;
       printf("\n\nRound Robin Scheduling Algorithm\n");
       printf("Note -\n1. CPU should never be idle\n");
       remain=pro;
       for(i=0;i<pro;i++)
       {
              a[i].p = i;
              a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       printf("Round Robin Algorithm");
       printf("\n***************************************\n");
       printf("Gantt Chart\n");
       time=a[0].art;
       printf("%d",time);
       for(time=a[0].art,i=0;remain!=0;)
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
              else if(a[i+1].art <= time)
                     i++;
              else
                     i=0;
}
}
int main()
{
	int bt[10],p[10],at[10],priority[10],n,i;
	struct times x[100];
	printf("Enter total number of process:");
	scanf("%d",&n);
	printf("\nEnter Arrival Time,Burst Time and Priority of the processes\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\n",i);
		printf("Arrival Time:");
		scanf("%d",&x[i].art);
		printf("Burst Time:");
		scanf("%d",&x[i].but);
		printf("Priority:");
		scanf("%d",&x[i].pr);
		p[i]=i+1;
	}

	//roundrobin(x,n);
	//priorityy(x,n);
	
	roundrobin(x,n);
	sleep(10);
	
	priorityy(x,n);
	sleep(10);
	
	fcfs(x,n);
	sleep(10);

	
	getch();
	return(0);

}

