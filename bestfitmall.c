#include<stdio.h>
#include<stdlib.h>
struct process
{
    int psize;
    int alloc;
    struct process *next;
}*phead=NULL,*pcurrent=NULL;
struct block
{
    int bsize;
    int bnum;
    struct block *next;
}*bhead=NULL,*bcurrent=NULL,*bestfit;
void main()
{
    int p,b,i,j;
    printf("Enter no.of processes: ");
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        struct process *pnewnode=(struct process*)malloc(sizeof(struct process));
        printf("Enter size of process P%d: ",i+1);
        scanf("%d",&pnewnode->psize);
        pnewnode->next=NULL;
        pnewnode->alloc=-1;
        if(phead==NULL)
        {
            phead=pnewnode;
            pcurrent=pnewnode;
        }
        else{
            pcurrent->next=pnewnode;
            pcurrent=pnewnode;
        }
    }
    printf("Enter no.of blocks: ");
    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        struct block *bnewnode=(struct block*)malloc(sizeof(struct block));
        printf("Enter size of block B%d: ",i+1);
        scanf("%d",&bnewnode->bsize);
        bnewnode->next=NULL;
        bnewnode->bnum=i+1;
        if(bhead==NULL)
        {
            bhead=bnewnode;
            bcurrent=bnewnode;
        }
        else
        {
            bcurrent->next=bnewnode;
            bcurrent=bnewnode;
        }
    }
    struct process *pnewnode;
    struct block *bnewnode;
    for(struct process *temp1=phead;temp1!=NULL;temp1=temp1->next)
    {
    bestfit=NULL;
    for(struct block*temp2=bhead;temp2!=NULL;temp2=temp2->next)
    {
        if(bnewnode->bsize>=pnewnode->psize)
        {
            if(bestfit==NULL||bestfit->bsize>bnewnode->bsize)
            {
                bestfit=bnewnode;
            }
        }
    }
        if(bestfit!=NULL)
        {
        pnewnode->alloc=bestfit->bnum;
        bnewnode->bsize-=pnewnode->psize;
        }
    }
    printf("Process\t\tProcess size\t\tBlock no.\n");
    for(struct process *temp1=phead;temp1!=NULL;temp1=temp1->next)
    {
        printf("Pi%d\t\t\t%d\t\t\t",(pnewnode-phead)+1,pnewnode->psize);
        if(pnewnode->alloc!=-1)
        {
            printf("%d\n",(pnewnode->alloc)+1);
        }
        else{
            printf("Not allocated");
        }
    }

}