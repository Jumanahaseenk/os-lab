#include<stdio.h>
#include<conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
int i,j;
printf("********** Banker's Algo ************\n");
input();
show();
cal();
getch();
return 0;
}
void input()
{
int i,j;
printf("Enter the no of Processes\t");
scanf("%d",&n);
printf("Enter the no of resources instances\t");
scanf("%d",&r);
printf("Enter the Max Matrix\n");
for(i=0;i<n;i++) {
for(j=0;j<r;j++) {
scanf("%d",&max[i][j]);
}}
printf("Enter the Allocation Matrix\n");
for(i=0;i<n;i++) {
for(j=0;j<r;j++) {
scanf("%d",&alloc[i][j]);
}}
printf("Enter the available Resources\n");
for(j=0;j<r;j++) {
scanf("%d",&avail[j]);
}}
void show() {
int i,j,need[10][10]
;
//find need matrix
for(i=0;i<n;i++) {
for(j=0;j<r;j++) {
need[i][j]=max[i][j]
-alloc[i][j];
}}
printf("Process\t Allocation\t Max\t\t Need\tAvailable\t");
for(i=0;i<n;i++) {
printf("\nP%d\t ",i);
for(j=0;j<r;j++) {
printf("%d   ",alloc[i][j]); }
printf("\t");
for(j=0;j<r;j++) {
printf("%d  ",max[i][j]); }
printf("\t");
for(j=0;j<r;j++) {
printf("%d  ",need[i][j]); }
printf("\t");
if(i==0) {
for(j=0;j<r;j++)
printf("%d  ",avail[j]);
}}}
void cal() {
    int finish[100], flag = 1, c1 = 0;
    int i, j;
    
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    
    printf("\n");

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int c = 0;
                for (j = 0; j < r; j++) {
                    if (need[i][j] <= avail[j]) {
                        c++;
                    } else {
                        break;
                    }
                }
                if (c == r) {
                    for (j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    flag = 1;
                    printf("P%d->", i);

                    // Print the updated available resources
                    printf("\nAvailable resources after allocating to P%d: ", i);
                    for (j = 0; j < r; j++) {
                        printf("%d ", avail[j]);
                    }
                    printf("\n");

                    // Update the need matrix for other processes
                    // (You might not need this if you're using a global need matrix)
                    for (j = 0; j < r; j++) {
                        need[i][j] = 0; // Since the process has finished, its need becomes 0
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (finish[i] == 1) {
            c1++;
        } else {
            printf("P%d->", i);
        }
    }

    if (c1 == n) {
        printf("\nThe system is in a safe state");
    } else {
        printf("\nProcesses are in deadlock");
        printf("\nThe system is in an unsafe state");
    }
}
