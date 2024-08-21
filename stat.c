#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
void main()
{
    struct stat s;
    stat("hello.txt",&s);
    printf("Size of program: %ld",s.st_dev);
    printf("Device id: %ld",s.st_dev);
    printf("File last accessed: %s",ctime(&s.st_atime));
    printf("Modified: %s",ctime(&s.st_mtime));
}