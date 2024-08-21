#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, f, pf = 0, count = 0, i, j, k, rs[25], m[10];

    // Get the length of the reference string
    printf("Enter length of reference string: ");
    scanf("%d", &n);

    // Get the reference string
    printf("Enter reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    // Get the number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1 (empty)
    for (i = 0; i < f; i++) {
        m[i] = -1;
    }

    // Iterate through each page reference
    for (i = 0; i < n; i++) {
        // Check if the page is already in one of the frames
        for (k = 0; k < f; k++) {
            if (rs[i] == m[k]) {
                break;
            }
        }

        // If the page was not found in any frame (page fault occurs)
        if (k == f) {
            m[count] = rs[i]; // Place the page in the frame at position `count`
            count = (count + 1) % f; // Update count for FIFO circular replacement
            pf++; // Increment page fault count
        }

        // Print the current state of frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-"); // Print '-' for empty frames
        }

        // Print page fault message if it occurred
        if (k == f) {
            printf("\tPF No.%d", pf);
        }

        printf("\n");
    }

    // Print total number of page faults
    printf("Total number of page faults: %d\n", pf);
}
