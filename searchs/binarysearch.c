#include <stdio.h>

// needs to be sorted

void binarySearchRecursive(int arr[], int left, int right, int number) {
    if (right >= left) {
        int middle = (left + right)/2;

        if (number == arr[middle]) {
            printf("The number %d exists in this array!\n", number);
            return;
        }

        if (number < arr[middle]) {
            return binarySearchRecursive(arr, left, middle - 1, number);
        }

        return binarySearchRecursive(arr, middle + 1, right, number);
    }

    printf("The number %d doesn't exists in this array!\n", number);
}

void binarySearchNonRecursive(int arr[], int number) {
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]) - 1;

    while (left <= right) {
        int middle = (left + right)/2;

        if (number == arr[middle]) {
            printf("The number %d exists in this array!", number);
            return;
        }

        else if (number < arr[middle]) {
            right = middle - 1;
        }

        else {
            left = middle + 1;
        }
    }

    printf("The number %d doesn't exists in this array!", number);
    return;
}
