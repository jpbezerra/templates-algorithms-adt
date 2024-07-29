#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int hoarePartition(int arr[], int left, int right) {
    int p = arr[left];
    int i = left;
    int j = right + 1;

    do {
        do {
            i++;
        } while (arr[i] < p && i < right);

        do {
            j--;
        } while (arr[j] > p);

        swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[i], &arr[j]);
    swap(&arr[left], &arr[j]);

    return j;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int split = hoarePartition(arr, left, right);
        quickSort(arr, left, split - 1);
        quickSort(arr, split + 1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nFinish!");
}

int main() {
    int arr[] = {64, 35, 78, 12, 91, 84, 85, 32, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}
