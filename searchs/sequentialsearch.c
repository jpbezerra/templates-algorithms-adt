#include <stdio.h>

void search(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            printf("The number %d exists in this array!", number);
            return;
        }
    }
    
    printf("The number %d doesn't exists in this array!", number);
}

int main() {
    int arr[] = {64, 35, 78, 12, 91, 84, 85, 32, 67}; // don't need to be sorted
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 123;
    search(arr, size, number); 

    return 0;
}