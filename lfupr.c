#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,f,pf=0,rs[25],flag[25],m[10],freq[10],count[10],min=0,i,j;
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
    for(j=0;j<f;j++)
    {
        m[j]=-1;
        freq[j]=0;
        count[j]=0;
    }
    for(i=0;i<n;i++)
    {
       for(j=0;j<f;j++)
       {
        if(m[j]==rs[i])
        {
            flag[i]=1;
            freq[j]++;
            break;
        }
       }
       if(flag[i]==0)
       {
        if(i<f)
        {
            m[i]=rs[i];
            freq[i]=1;
            count[i]=i;
        }
        else
        {
          min=0;
          for(j=0;j<f;j++)
          {
            if((freq[min]<freq[j])||(freq[j]==freq[min]&&count[min]>count[j]))
            {
                min=j;
            }
          }
          m[min]=rs[i];
          freq[min]=1;
          count[min]=i;
        }
        pf++;
       }
       for(j=0;j<f;j++)
       {
        printf("\t%d",m[j]);
       }
       if(flag[i]==0)
       {
        printf("\tPF no.: %d",pf);
       }
       printf("\n");
    }
    printf("Total no.of page faults: %d",pf);
}