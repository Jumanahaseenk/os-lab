#include<stdio.h>
#include<stdlib.h>
void main()
{
    int rq[20],initial,index,i,j,n,move,size,totalmov=0,temp;
    printf("Enter no.of requests: ");
    scanf("%d",&n);
    printf("Enter request sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter initial position of head: ");
    scanf("%d",&initial);
    printf("Enter size of disk: ");
    scanf("%d",&size);
    printf("Enter direction of movement 1 for high & 0 for low: ");
    scanf("%d",&move);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(initial<rq[i])
        {
            index=i;
            break;
        }
    }

    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            totalmov+=abs(rq[i]-initial);
            initial=rq[i];
        }
        totalmov+=abs(size-1-initial);
        initial=size-1;
        for(i=index-1;i>=0;i--)
        {
            totalmov+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
        totalmov+=abs(rq[i]-initial);
        initial=rq[i];
        }
        totalmov+=abs(initial-0);
        initial=0;
        for(i=index;i<n;i++)
        {
            totalmov+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("Total head movement: %d",totalmov);
}