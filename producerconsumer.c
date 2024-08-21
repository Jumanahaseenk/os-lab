#include<stdio.h>
#include<stdlib.h>
int empty,full=0,mutex=1,x=0;
int signal(int s)
{
    return ++s;
}
int wait(int s)
{
    return --s;
}
void producer()
{
    empty=wait(empty);
    mutex=wait(mutex);
    x++;
    printf("Producer produces item %d",x);
    mutex=signal(mutex);
    full=signal(full);
}
void consumer()
{
 full=wait(full);
 mutex=wait(mutex);
 printf("Consumer consumes item %d",x);
 x--;
 mutex=signal(mutex); 
 empty=signal(empty);  
}
void main()
{
    int n,c;
    printf("Enter no.of slots: ");
    scanf("%d",&n);
    empty=n;
    printf("1.Producer\t2.Consumer\t3.Exit\n");
    while(1)
    {
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: if(mutex==1&&empty!=0)
        {
            producer();
        }
        else{
            printf("\nThe buffer is full");
        }
        break;
        case 2: if(mutex==1&&full!=0)
        {
            consumer();
        }
        else{
            printf("\nThe buffer is empty");
        }
        break;
        case 3: exit(0);
        default: printf("Invalid choice");
    }
    }
}