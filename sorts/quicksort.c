#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}


int HoarePartition(int arr[], int left, int right) {
    int p = arr[left];
    int i = left;
    int j = right + 1;

    do {
       do {
            i++;
       } while (arr[i] < p);

       do {
            j--;
       } while (arr[j] > p);
       
       swap(&arr[i], &arr[j]);
    } while (i < j);
    
    swap(&arr[i], &arr[j]);
    swap(&arr[left], &arr[j]);

    return j;
}


void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int split = HoarePartition(arr, left, right);
        QuickSort(arr, left, split - 1);
        QuickSort(arr, split + 1, right);
    }
}


void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nFinish!");
}


int main() {
    int arr[] = {64, 35, 78, 12, 91, 84, 85, 32, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    PrintArray(arr, size);

    return 0;
}