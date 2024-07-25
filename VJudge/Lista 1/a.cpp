#include <iostream>

using namespace std;

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
            array[curr] = temp[i2++];
        } 
            
        else if(i2 > r) { 
            array[curr] = temp[i1++];
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
    long long int soma = 0;
    int chocolates;
    cin >> chocolates;

    int array_choc[chocolates];

    for (int i = 0; i < chocolates; i++) {
        cin >> array_choc[i];
        soma += array_choc[i];
    }

    MergeSort(array_choc, 0, chocolates - 1);

    long long int coupons;
    cin >> coupons;

    long long int coup;

    for (int i = 0; i < coupons; i++) {
        cin >> coup;
        long long int soma_prov = soma;

        for (int j = 0; j < 1; j++) {
            soma_prov -= array_choc[chocolates - coup];
            cout << soma_prov << endl;           
        }
    }
    return 0;
}
