#include <stdio.h>

void merge(int arr[], int left, int right) {
    int temp[right + 1];

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

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right)/2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, right);
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
    merge_sort(arr, 0, size - 1);
    print_array(arr, size);

    return 0;
}