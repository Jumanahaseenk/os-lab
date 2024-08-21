#include<stdio.h>
#include<stdlib.h>
int p,r,alloc[10][10],max[10][10],need[10][10],avail[10];
int i,j,k;
void readmatrix(int matrix[p][r])
{
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printmatrices()
{
    printf("Process\tAllocation\t\t\tMax\t\t\tNeed\t\t   Available");
    for(i=0;i<p;i++)
    {
        printf("\nP%d\t",i);
        for(j=0;j<r;j++)
        {
            printf("%d ",alloc[i][j]);
           printf("\t");
        }
        for(j=0;j<r;j++)
        {
            printf("%d ",max[i][j]);
            printf("\t");
        }
        
        for(j=0;j<r;j++)
        {
            printf("%d ",need[i][j]);
           printf("\t");
        }
        if(i==0)
        {
             printf("\t");
            for(j=0;j<r;j++)
            {
                printf("%d ",avail[j]);
                printf("\t");
            }
        }
    }
}
void banker()
{
    int c,c1,finish[10],flag=1;
    for(i=0;i<p;i++)
    {
        finish[i]=0;
    }
    while(flag)
    {
        flag=0;
        for(i=0;i<p;i++)
        {
            c=0;
            for(j=0;j<r;j++)
            {
                if((finish[i]==0)&&(need[i][j]<=avail[j]))
                {
                    c++;
                    if(c==r)
                    {
                        for(k=0;k<r;k++)
                        {
                            avail[k]+=alloc[i][j];
                            finish[i]=1;
                            flag=1;
                        }
                        printf("\nP%d-->",i);
                        if(finish[i]==1)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<p;i++)
    {
        if(finish[i]==1)
        {
            c1++;
        }
        else
        {
            printf("P%d-->",i);
        }
    }
    if(c1==p)
    {
        printf("The system is in safe state");
    }
    else
    {
        printf("Processes are in deadlock\n");
        printf("The system is in unsafe state");
    }
}
int main()
{
    printf("Enter no.of processes: ");
    scanf("%d",&p);
    printf("Enter no.of resources: ");
    scanf("%d",&r);
    printf("Enter allocation matrix: ");
    readmatrix(alloc);
    printf("Enter max matrix: ");
    readmatrix(max);
    printf("Enter available resources: ");
    for(i=0;i<r;i++)
    {
        scanf("%d",&avail[i]);
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printmatrices();
    banker();
}