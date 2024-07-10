#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int right, int temp[]) {
    for (int i = 0; i <= right ; i++) {
        temp[i] = arr[i];
    }
    
    int middle = (left + right) / 2;

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
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle, temp);
        mergeSort(arr, middle + 1, right, temp);
        merge(arr, left, right, temp);
    }
}

void printArray(int arr[], int size) {
    printf("%d", arr[0]);
    for (int i = 1; i < size; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");
}

int main() {
    int cases, size, element;
    scanf("%d", &cases);
    
    while (cases--) {
        scanf("%d", &size);
        int array[size];
        int temp[size];

        for (int i = 0; i < size; i++) {
            scanf("%d", &element);
            array[i] = element;
        }
        
        mergeSort(array, 0, size - 1, temp);
        printArray(array, size);
    }
    
    return 0;
}