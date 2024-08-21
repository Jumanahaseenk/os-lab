#include<stdio.h>
#include<stdlib.h>

struct process {
    int psize;
    int alloc;
    struct process *next;
} *phead = NULL, *pcurrent = NULL;

struct block {
    int bsize;
    int bnum;
    struct block *next;
} *bhead = NULL, *bcurrent = NULL, *bestfit;

int main() {
    int np, nb, i;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    // Input the sizes of the processes
    for (i = 0; i < np; i++) {
        struct process *newProcess = (struct process *)malloc(sizeof(struct process));
        printf("Enter size of process P%d: ", i + 1);
        scanf("%d", &newProcess->psize);
        newProcess->alloc = -1; // Initialize as not allocated
        newProcess->next = NULL;

        if (phead == NULL) {
            phead = newProcess;
            pcurrent = newProcess;
        } else {
            pcurrent->next = newProcess;
            pcurrent = newProcess;
        }
    }

    // Input the number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    // Input the sizes of the blocks
    for (i = 0; i < nb; i++) {
        struct block *newBlock = (struct block *)malloc(sizeof(struct block));
        printf("Enter size of block B%d: ", i + 1);
        scanf("%d", &newBlock->bsize);
        newBlock->bnum = i + 1; // Block number
        newBlock->next = NULL;

        if (bhead == NULL) {
            bhead = newBlock;
            bcurrent = newBlock;
        } else {
            bcurrent->next = newBlock;
            bcurrent = newBlock;
        }
    }

    // Perform Best Fit allocation
    for (struct process *proc = phead; proc != NULL; proc = proc->next) {
        bestfit = NULL;
        for (struct block *blk = bhead; blk != NULL; blk = blk->next) {
            if (blk->bsize >= proc->psize) {
                if (bestfit == NULL || blk->bsize < bestfit->bsize) {
                    bestfit = blk;
                }
            }
        }

        if (bestfit != NULL) {
            proc->alloc = bestfit->bnum; // Storing the block number
            bestfit->bsize -= proc->psize;
        }
    }

    // Print the allocation result
    printf("Process\t\tProcess size\t\tBlock no.\n");
    for (struct process *proc = phead; proc != NULL; proc = proc->next) {
        printf("P%d\t\t\t%d\t\t\t", (proc - phead) + 1, proc->psize);
        if (proc->alloc != -1) {
            printf("%d\n", proc->alloc);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
