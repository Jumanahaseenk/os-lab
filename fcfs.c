#include<stdio.h>
int main()
{
    int n,at[10],bt[10],ct[10],tat[10],wt[10],sum,i,j,k;
    float totaltat=0,totalwt=0;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    printf("Enter arrival time of process %d: ",(i+1));
    scanf("%d",&at[i]);
    printf("Enter burst time of process %d: ",(i+1));
    scanf("%d",&bt[i]);
    }
    sum=at[0];
    for(j=0;j<n;j++)
    {
    sum+=bt[j];
    ct[j]=sum;
    }

    for(k=0;k<n;k++)
    {
        tat[k]=ct[k]-at[k];
        totaltat=totaltat+tat[k];

        wt[k]=tat[k]-bt[k];
        totalwt=totalwt+wt[k];
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i=0;i<n;i++)
    {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average turn around time=  %f",totaltat/n);
    printf("Average waiting around time=  %f",totalwt/n);
    return 0;
}