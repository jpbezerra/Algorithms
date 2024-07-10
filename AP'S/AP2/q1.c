#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int hoarePartition(int arr[], int left, int right) {
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

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int split = hoarePartition(arr, left, right);
        quickSort(arr, left, split - 1);
        quickSort(arr, split + 1, right);
    }
}

void printArr(int arr[], int size) {
    printf("%d", arr[size]);
    for (int i = size - 1; i >= 0; i--) {
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

        for (int i = 0; i < size; i++) {
            scanf("%d", &element);
            array[i] = element;
        }
        
        quickSort(array, 0, size - 1);
        printArr(array, size - 1);
    }
    
    return 0;
}