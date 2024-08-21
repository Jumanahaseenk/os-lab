#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,m;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    printf("Enter no.of resources: ");
    scanf("%d",&m);
    int max[n][m],alloc[n][m],need[n][m],avail[m],work[m],finish[n],safe[n],sindex=0,flag,i,j,k,w;
    printf("Enter allocation matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter max matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter available: ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("The need matris is: \n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d\t",need[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                flag=0;
            }
            for(j=0;j<m;j++)
            {
                if(work[j]<need[i][j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                safe[sindex++]=i;
                for(w=0;w<m;w++)
                {
                    work[w]+=alloc[i][w];
                }
                finish[i]=1;
            }
        }
            
    }
   /* printf("The safe sequence: ");
    for(i=0;i<n;i++)
    {
        if(finish[i]==1)
        {
            printf("P%d-->",safe[i]);
        }
    }*/
   int isSafe = 1;
    for(int i = 0; i < n; i++) {
        if(finish[i] == 0) {
            isSafe = 0;
            break;
        }
    }

    if(isSafe) {
        printf("The system is in a safe state.\nSafe sequence is: ");
        for(int i = 0; i < n; i++) {
            printf("P%d", safe[i]);
            if(i != n - 1) {
                printf(" --> ");
            }
        }
        printf("\n");
    } else {
        printf("The system is not in a safe state.\n");
    }
}
