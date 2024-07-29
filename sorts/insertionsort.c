#include <stdio.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int v = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = v;
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
    insertionSort(arr, size);
    print_array(arr, size);

    return 0;
}
