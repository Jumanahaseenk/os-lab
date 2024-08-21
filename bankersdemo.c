#include<stdio.h>
void main(){
    int n,m;
    printf("enter the no.of PROCESSES");
    scanf("%d",&n);
    printf("nter the noof RESOURCES");
    scanf("%d",&m);
    int need[n][m],alloc[n][m],max[n][m],avail[m],finish[n],safe[n],sindex=0,flag,work[m];
    printf("enter the MAX matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
     printf("enter the ALLOCATE matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
     printf("enter the AvAilabLE");
    for(int j=0;j<m;j++){
            scanf("%d",&avail[j]);
        }

   printf("NEED matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
    }
        }
    for(int i=0;i<n;i++){
     printf("\n");
        for(int j=0;j<m;j++){
            printf("%d",need[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        finish[i]=0;
    }
        for(int i=0;i<m;i++){
        work[i]=avail[i];
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(finish[i]==0){
            flag=0;
            for(int j=0;j<m;j++){
                if(need[i][j]>work[j]){
                    flag=1;
                    break;
                }
            }
                if(flag==0){
                    safe[sindex++]=i;
                 for(int w=0;w<m;w++){
                    work[w]+=alloc[i][w];}
                    finish[i]=1;
                 }
            }
        }
    }
    printf("the safe sequence: ");
    for(int i=0;i<n;i++){
            if(finish[i]==1)
            {
                printf("P%d ",safe[i]);
            }
    }
    }