#include <stdio.h>

void Merge(int array[], int l, int r) {
    int temp[r+1];

    for (int i = l; i <= r; i++) {
       temp[i] = array[i]; 
    }

    int m = (l + r)/2;
    int i1 = l;
    int i2 = m + 1;
        
    for (int curr = l; curr <= r; curr++) {

        if(i1 == (m + 1)) {
            array[curr]=temp[i2++];
        } 
            
        else if(i2 > r) { 
            array[curr]=temp[i1++];
        } 
            
        else if(temp[i1] <= temp[i2]) {
            array[curr] = temp[i1++];
        } 
            
        else {
            array[curr] = temp[i2++];
        }
    }
}


void MergeSort(int array[], int l, int r) {
    if (l < r) {
        int middle = (l + r) / 2;
        MergeSort(array, l, middle);
        MergeSort(array, middle + 1, r);
        Merge(array, l, r);
    }
}

int main() {
    int casos;
    scanf("%d", &casos);
    
    for (int i = 0; i < casos; i++) {
        int range;
        scanf("%d", &range);

        int array[range];

        for (int j = 0; j < range; j++) {
            scanf("%d", &array[j]);
        }

        MergeSort(array, 0, range - 1);

        for (int p = 0; p < range; p++) {
            printf("%d", array[p]);
        }
    }

    return 0;
}