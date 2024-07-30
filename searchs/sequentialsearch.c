#include <stdio.h>

// don't need to be sorted

void sequentialSearch(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            printf("The number %d exists in this array!", number);
            return;
        }
    }

    printf("The number %d doesn't exists in this array!", number);
}
