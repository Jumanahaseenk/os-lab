#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
    int shmid;
    void *sharedmemory;
    char buff[50];
    shmid=shmget(1111,1024,0666|IPC_CREAT);
    printf("ID of the shared segment is: %d",shmid);
    sharedmemory=shmat(shmid,NULL,0);
    printf("\nThe segment is attached to: %p",sharedmemory);
    printf("\nEnter something: ");
    scanf("%[^\n]",&buff);
    strcpy(sharedmemory,buff);
    printf("You wrote: ");
    printf("%s",(char*)sharedmemory);
}
