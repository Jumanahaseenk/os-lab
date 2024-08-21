#include<stdio.h>
#include<stdlib.h>
void main()
{
    int rq[20],totalmov=0,initial,n,i;
    printf("Enter no. of requests: ");
    scanf("%d",&n);
    printf("Enter request sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter initial position of head: ");
    scanf("%d",&initial);
    for(i=0;i<n;i++)
    {
        totalmov+=abs(rq[i]-initial);
        initial=rq[i];
    }
    printf("Total head movements: %d ",totalmov);

}