#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int prio;
    int wt;
    int tat;
}p[10],temp;
void main()
{
int i,j,n,currtime=0,totwt=0,tottt=0;
float avgwt,avgtt;
printf("Enter no.of processes: ");
scanf("%d",&n);
printf("\nEnter process id,arrival time,burst time and priority of the processes:  ");
for(i=0;i<n;i++)
{
    scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].prio);
}
//struct proess temp;
for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
       if(p[i].at>p[j].at)
       {
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
       }
    }
}

for(i=0;i<n;i++)
{
    int high=i;
    for(j=i+1;j<n;j++)
    {
        if((p[j].at<=currtime)&&p[j].prio<p[high].prio)
        {
            high=j;
        }
    }
    temp=p[i];
    p[i]=p[high];
    p[high]=temp;
    if(currtime<p[i].at)
    {
        currtime=p[i].at;
    }
    p[i].wt=currtime-p[i].at;
    currtime+=p[i].bt;
    p[i].tat=p[i].wt+p[i].bt;
    totwt+=p[i].wt;
    tottt+=p[i].tat;
}
avgwt=(float)totwt/n;
avgtt=(float)tottt/n;
printf("Process\tAT\tBT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
    }
    avgwt=(float)totwt/n;
    avgtt=(float)tottt/n;
    printf("\nTotal turnaround time: %d",tottt);
    printf("\nTotal waiting time: %d",totwt);
    printf("\nAverage turnaround time: %f",avgtt);
    printf("\nAverage waiting time: %f",avgwt);

}
