#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[10];
void sortbyat(struct process p[],int n)
{
    struct process temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void main()
{
    int totwt=0,tottt=0;
    float avgwt,avgtt;
    int i,n;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    printf("\nEnter process id,arrival time and burst time of proceses:  \n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    sortbyat(p,n);
    
    p[0].wt=0;
    p[0].ct=p[0].at+p[0].bt;
    p[0].tat=p[0].ct-p[0].at;
    for(i=1;i<n;i++)
    {
        if(p[i-1].ct>p[i].at)
        {
            p[i].wt=p[i-1].ct-p[i].at;
        }
        else
        {
            p[i].wt=0;
        }
        p[i].ct=p[i].at+p[i].bt+p[i].wt;
        p[i].tat=p[i].ct-p[i].at;
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for(i=0;i<n;i++)
    {
        totwt+=p[i].wt;
        tottt+=p[i].tat;
    }
    avgwt=(float)totwt/n;
    avgtt=(float)tottt/n;
    printf("\nTotal turnaround time: %d",tottt);
    printf("\nTotal waiting time: %d",totwt);
    printf("\nAverage turnaround time: %f",avgtt);
    printf("\nAverage waiting time: %f",avgwt);

}