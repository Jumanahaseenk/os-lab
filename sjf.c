#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int pid;
    int btime;
    int wtime;
    int atime;
    int tatime;
}sp;
int main()
{
    int n,i,j,k,tbm=0,totalwtime=0,totaltatime;
    sp *p,t;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    p=(sp*)malloc(n* sizeof(sp));
    printf(" Enter arrival time and burst time for\n");
    for(i=0;i<n;i++)
    {
    printf("Process %d ",i+1);
    scanf("%d %d",&p[i].atime,&p[i].btime);
    p[i].pid=i+1;
    p[i].wtime=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].atime>p[j].atime||p[i].atime==p[j].atime&&p[i].btime>p[j].btime)
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    printf("Process\tAT\tBT\tWT\n\n");
    for(i=0;i<n;i++)
    {
        p[i].wtime=tbm-p[i].atime-p[i].btime;
        tbm+=p[i].btime;
        p[i].tatime=tbm-p[i].atime;
        totalwtime+=p[i].wtime;
        printf("%d\t%d\t%d\t%d\n",i+1,p[i].atime,p[i].btime,p[i].wtime);
    }
    totaltatime=tbm;
    printf("Total waiting time= %d",totalwtime);
    printf("Average waiting time= %f",(totalwtime/n));
    printf("Total turnaround time= %d",totaltatime);
    printf("Average turnaround time= %f",(totaltatime/n));

}