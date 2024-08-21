#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,f,pf=0,rs[25],flag[25],m[10],count[10],min,i,j,next=0;
    printf("Enter length of reference string: ");
    scanf("%d",&n);
    printf("Enter reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter no.of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        count[i]=0;
        m[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<f;j++)
        {
            if(rs[i]==m[j])
            {
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        
        if(flag[i]==0)
        {
            if(i<f)
            {
              m[i]=rs[i];
              count[i]=next;
              next++;
            }
            else
            {
             min=0;
             for(j=0;j<f;j++)
             {
                if(count[min]>count[j])
                {
                    min=j;

                }
             }
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
            pf++;
        }
        for(j=0;j<f;j++)
        {
            printf("\t%d",m[j]);
        }
        if(flag[i]==0)
        {
            printf("\tPFno.: %d",pf);
        }
        printf("\n");
    }
    printf("Total no.of page faults using LRU: %d",pf);
}
