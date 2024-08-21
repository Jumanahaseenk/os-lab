#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float calculateMean(int arr[], int n);
float calculateMedian(int arr[], int n);
int calculateMode(int arr[], int n);

// Function to calculate the mean of elements in the array
float calculateMean(int arr[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the median of elements in the array
float calculateMedian(int arr[], int n) {
    // Sort the array
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculate median
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

// Function to calculate the mode of elements in the array (assuming unimode)
int calculateMode(int arr[], int n) {
    int maxCount = 0, mode = -1;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == arr[i]) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 5, 4, 5, 6, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    float mean = calculateMean(arr, n);
    printf("Mean: %.1f\n", mean);

    float median = calculateMedian(arr, n);
    printf("Median: %.1f\n", median);

    int mode = calculateMode(arr, n);
    printf("Mode: %d\n", mode);

    return 0;
}
