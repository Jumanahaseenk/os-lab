#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
    pid_t procid=fork();
    if(procid<0)
    {
        printf("Child not created");
        exit(0);
    }
    else
    {
        printf("Child created: %d",getpid());  
    }
    pid_t w=wait(NULL);
    printf("\n%d",w);
    execlp("ls","ls",NULL);
    exit(0);
}