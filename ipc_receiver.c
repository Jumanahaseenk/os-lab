#include<stdio.h>
#include<sys/types.h>
#include <sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int shmid;
    void *shared_memory;
    char buff[40];
    shmid=shmget((key_t)1000,1024,0666);
    /*if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }*/
    printf("ID of the shared memory is: %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("The shared memory is attached to: %p\n",shared_memory);
    printf("Data read from shared memory is: %s",(char *)shared_memory);
}