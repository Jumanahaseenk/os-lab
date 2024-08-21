#include<stdio.h>
#include<stdlib.h>
void main()
{
    int np,nb,bsize[10],psize[10],allocation[10],i,j;
    printf("Enter no.of processes: ");
    scanf("%d",&np);
    printf("Enter process sizes:");
    for(i=0;i<np;i++)
    {
        printf("P%d: ",i+1);
        scanf("%d",&psize[i]);
    }
    printf("Enter no.of blocks: ");
    scanf("%d",&nb);
    printf("Enter block sizes:");
    for(j=0;j<nb;j++)
    {
        printf("B%d: ",j+1);
        scanf("%d",&bsize[j]);
    }
    for(i=0;i<10;i++)
    {
        allocation[i]=-1;
    }
    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
          if(bsize[j]>=psize[i])
          {
            allocation[i]=j;
            bsize[j]-=psize[i];
            break;
          }
        }
    }
    printf("Process\t\tProcess size\t\tBlock no.\n");
    for(i=0;i<np;i++)
    {
    printf("P%d\t\t\t%d\t\t\t",i+1,psize[i]);
    if(allocation[i]!=-1)
    {
        printf("%d\n",allocation[i]+1);
    }
    else
    {
        printf("Not allocated\n");
    }
    }
}