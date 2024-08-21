#include<stdio.h>
#include<stdlib.h>
void main()
{
    int np,nb,psize[10],bsize[10],allocation[10],i,j;
    printf("Ener no.of processes: ");
    scanf("%d",&np);
    printf("Enter process sizes\n");
    for(i=0;i<np;i++)
    {
       printf("P%d: ",i+1);
       scanf("%d",&psize[i]);
    }
    printf("Ener no.of blocks: ");
    scanf("%d",&nb);
    printf("Enter block sizes\n");
    for(i=0;i<nb;i++)
    {
       printf("B%d: ",i+1);
       scanf("%d",&bsize[i]);
    }
    for(i=0;i<np;i++)
    {
        allocation[i]=-1;
    }
    for(i=0;i<np;i++)
    {
        int worstfit=-1;
        for(j=0;j<nb;j++)
        {
          if(bsize[j]>=psize[i])
          {
            if(worstfit==-1||bsize[worstfit]<bsize[j])
            {
                worstfit=j;
            }
          }
        }
        if(worstfit!=-1)
        {
            allocation[i]=worstfit;
            bsize[worstfit]-=psize[i];
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
        else{
            printf("Not allocated");
        }
    }
}