#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i <= size - 2; i++) {
        for (int j = 0; j <= size - 2 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}
