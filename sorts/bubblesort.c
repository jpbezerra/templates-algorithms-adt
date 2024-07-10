#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i <= size - 2; i++) {
        int min = i;

        for (int j = 0; j <= size - 2 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nFinish!");
}

int main() {
    int arr[] = {64, 35, 78, 12, 91, 84, 85, 32, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, size);
    print_array(arr, size);

    return 0;
}