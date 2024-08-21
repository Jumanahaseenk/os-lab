#include<stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} p[10];

void sort(struct process p[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sort primarily by arrival time (at), and if equal, by burst time (bt)
            if (p[i].at > p[j].at || (p[i].at == p[j].at && p[i].bt > p[j].bt)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void main() {
    int i, n, totwt = 0, tottt = 0;
    float avgwt, avgtt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process id, arrival time, and burst time of processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    // Sort processes by arrival time and burst time using the sort function
    sort(p, n);

    // Calculate completion time, turnaround time, and waiting time for each process
    p[0].wt = 0;
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    for (i = 1; i < n; i++) {
        // Calculate waiting time
        if (p[i - 1].ct > p[i].at) {
            p[i].wt = p[i - 1].ct - p[i].at;
        } else {
            p[i].wt = 0;
        }

        // Calculate completion time, turnaround time
        p[i].ct = p[i].at + p[i].bt + p[i].wt;
        p[i].tat = p[i].ct - p[i].at;
    }

    // Print the process table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    // Calculate total turnaround time and total waiting time
    for (i = 0; i < n; i++) {
        totwt += p[i].wt;
        tottt += p[i].tat;
    }

    // Calculate average turnaround time and average waiting time
    avgwt = (float) totwt / n;
    avgtt = (float) tottt / n;

    // Print total and average turnaround time and waiting time
    printf("\nTotal turnaround time: %d", tottt);
    printf("\nTotal waiting time: %d", totwt);
    printf("\nAverage turnaround time: %f", avgtt);
    printf("\nAverage waiting time: %f\n", avgwt);
}
