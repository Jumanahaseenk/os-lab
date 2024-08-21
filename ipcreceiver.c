#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
void main()
{
    int shmid;
    char buff[20];
    void *sharedmemory;
    shmid=shmget(1111,1024,0666);
    printf("ID of the shared segment is: %d",shmid);
    sharedmemory=shmat(shmid,NULL,0);
    printf("\nThe shared segment is attached at: %p",sharedmemory);
    printf("\nRead from shared: %s",(char*)sharedmemory);
}