#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;
    return j2->profit - j1->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobSequencing(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;

    int slot[maxDeadline];
    int result[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, arr[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for (int i = 0; i < maxDeadline; i++)
        if (slot[i])
            printf("J%d ", result[i]);

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    struct Job arr[] = {
        {1,7,30},
        {2,8,29},
        {3,6,28},
        {4,2,27},
        {5,10,27},
        {6,12,26},
        {7,4,25},
        {8,6,24},
        {9,3,22},
        {10,5,21},
        {11,3,19},
        {12,4,19},
        {13,13,14},
        {14,1,11}
    };

    int n = sizeof(arr)/sizeof(arr[0]);
    jobSequencing(arr, n);

    return 0;
}
