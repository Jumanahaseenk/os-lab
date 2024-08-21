#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
void main()
{
    char s[10];
    DIR *dirptr;
    printf("Enter directory name: ");
    scanf("%s",&s);
    dirptr=opendir(s);
    if(dirptr==NULL)
    {
        printf("\nNo such directory");
        exit(1);
    }
    while(dptr=readdir(dirptr))
    {
        printf("%s\n",dptr->d_name);
    }
    closedir(dirptr);
}