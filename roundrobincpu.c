#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int tempbt;
    int completed;
}temp;
void sort(struct process p[],int n)
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
       if(p[j].at>p[j+1].at)
       {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
       }
    }
}
}
struct process queue[100];
void enqueue(struct process p)
{
    if(rear==-1)
    {
        front=rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=p;
}
struct process dequeue()
{
    struct process p=queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front++;
    }
    return p;
}
int isempty()
{
    return front==-1;
}
void tat_wt(struct process p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
}
void display(struct process p[],int n)
{
   printf("Process\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
   for(int i=0;i<n;i++)
   {
    printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
   }
   int totwt=0,tottt=0;
   for(int i=0;i<n;i++)
   {
    totwt+=p[i].wt;
    tottt+=p[i].tat;
   }
   float avgwt=(float)totwt/n;
   float avgtat=(float)tottt/n;
   printf("Total turnaround time: %d",tottt);
   printf("Total waiting time: %d",totwt);
   printf("Average turnaround time: %d",avgtat);
   printf("Average waiting time: %d",avgwt);
}
void roundrobin(struct process p[],int n,int tq)
{
    int completed=0,current_ct=0;
    enqueue(p[0]);
    int i;
    while(completed<n)
    {
        if(!isempty)
        {
            struct process pro=dequeue();
            if(pro.tempbt<=tq)
            {
                pro.tempbt=0;
                current_ct+=pro.tempbt;
                pro.completed=1;
                pro.ct=current_ct;
                completed++;
            }
            else{
                pro.tempbt-=tq;
                current_ct+=tq;
            }
            while(i<n&&p[i].at<=current_ct)
            {
                enqueue(p[i]);
                i++;
            }
            if(pro.tempbt>0)
            {
                enqueue(pro);
            }
            for(int j=0;j<n;j++)
            {
                if(p[j].pid==pro.pid)
                {
                    p[j]=pro;
                    break;
                }
                else{
                    current_ct++;
                }
            }

        }
    }
    tat_wt(p,n);
    display(p,n);
}
void main()
{
    int i,n,tq;
    struct process p[100];
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    printf("Enter process id,arrival time and burst time for processes: ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    sort(p,n);
    roundrobin(p,n,tq);
}