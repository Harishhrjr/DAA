#include <stdio.h>
void bucketSort(float arr[], int n) {
    float bucket[10][10];
    int bucketCount[10];

    for (int i = 0; i < 10; i++)
        bucketCount[i] = 0;

    for (int i = 0; i < n; i++) {
        int index = arr[i] * 10;
        bucket[index][bucketCount[index]++] = arr[i];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < bucketCount[i]; j++) {
            float key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = bucket[i][j];
        }
    }
}
int main() {
    printf("Harish.r CH.SC.U4cse24163\n");
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = 7;
    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    return 0;
}
