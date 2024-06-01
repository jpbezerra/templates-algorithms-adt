#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            
        }
        
        swap(&arr[i], &arr[min]);
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
    selection_sort(arr, size);
    print_array(arr, size);

    return 0;
}