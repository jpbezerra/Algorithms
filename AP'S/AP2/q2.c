#include <stdio.h>
#include <stdlib.h>

void binarySearch(int arr[], int left, int right, int search) {
    if (right >= left) {
        int middle = (left + right)/2;

        if (search == arr[middle]) {
            printf("%d\n", middle);
            return;
        }
        
        else if (search < arr[middle]) {
            return binarySearch(arr, left, middle - 1, search);
        }
        
        else {
            return binarySearch(arr, middle + 1, right, search);
        }
    }

    printf("x\n");
    return;
}

int main() {
    int size, element, numb, search;
    scanf("%d", &size);

    int array[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &element);
        array[i] = element;
    }
    
    scanf("%d", &numb);

    while (numb--) {
        scanf("%d", &search);
        binarySearch(array, 0, size - 1, search);
    }

    return 0;
}