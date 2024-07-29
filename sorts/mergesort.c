#include <stdio.h>

void merge(int arr[], int left, int right, int temp[]) {
    for (int i = left; i <= right; i++) {
        temp[i] = arr[i];
    }

    int middle = (left + right)/2;

    int i1 = left;
    int i2 = middle + 1;

    for (int curr = left; curr <= right; curr++) {
        if (i1 == middle + 1) {
            arr[curr] = temp[i2++];
        }

        else if (i2 > right) {
            arr[curr] = temp[i1++];
        }

        else if (temp[i1] <= temp[i2]) {
            arr[curr] = temp[i1++];
        }

        else {
            arr[curr] = temp[i2++];
        }
    }
}

void mergeSort(int arr[], int left, int right, int temp[]) {
    if (left < right) {
        int middle = (left + right)/2;
        mergeSort(arr, left, middle, temp);
        mergeSort(arr, middle + 1, right, temp);
        merge(arr, left, right, temp);
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
    int temp[size];
    mergeSort(arr, 0, size - 1, temp);
    printArray(arr, size);

    return 0;
}
