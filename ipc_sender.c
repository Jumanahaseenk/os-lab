#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    int shmid;
    void *shared_memory;
    char buff[40];
    shmid=shmget((key_t)1000,1024,0666|IPC_CREAT);
    printf("Id of the shared memory created is: %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("The segment is attached to: %p\n",shared_memory);
    printf("Write something: ");
    scanf("%[^\n]",&buff);
    strcpy(shared_memory,buff);
    printf("You wrote: %s\n",(char *)shared_memory);
}