#include <iostream>

using namespace std;

void Merge(long long int array[], int l, int r) {
    int temp[r+1];

    for (int i = l; i <= r; i++) {
       temp[i] = array[i]; 
    }

    int m = (l + r)/2;
    int i1 = l;
    int i2 = m + 1;
        
    for (int curr = l; curr <= r; curr++) {

        if (i1 == (m+1)) {
            array[curr] = temp[i2++];
        } 
            
        else if (i2 > r) { 
            array[curr] = temp[i1++];
        } 
            
        else if (temp[i1] <= temp[i2]) {
            array[curr] = temp[i1++];
        } 
            
        else {
            array[curr] = temp[i2++];
        }
    }
}


void MergeSort(long long int array[], int l, int r) {
    if (l < r) {
        int middle = (l + r) / 2;
        MergeSort(array, l, middle);
        MergeSort(array, middle + 1, r);
        Merge(array, l, r);
    }
}

int main() {
    long long int range;
    long long int value;
    long long int counter = 0;

    cin >> range >> value;

    long long int array[range];

    for (int i = 0; i < range; i++) {
        cin >> array[i];    
    }
    
    MergeSort(array, 0, range-1);

    for (int m = 0; m < range; m ++) {
        for (int j = m + 1; j < range; j++) {
            if (abs(array[m] - array[j]) == value) {
                counter++;
            }

            else if (abs(array[m] - array[j]) > value) {
                break;
            }
            
        }
        
    }
    
    cout << counter << endl;

    return 0;
}