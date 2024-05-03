#include <iostream>

using namespace std;

struct cand {
    string nome;
    int nota;
    int idade;
    int coloc;
};

void merge(cand array[], int l, int r) {
    cand temp[r+1];

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
            
        else if (temp[i1].nota < temp[i2].nota) {
            array[curr] = temp[i2++];
        } 

        else if (temp[i1].nota > temp[i2].nota) {
            array[curr] = temp[i1++];
        }
        
            
        else {

            if (temp[i1].idade > temp[i2].idade) {
                array[curr] = temp[i2++];
            }
            
            else {
                array[curr] = temp[i1++];
            }
        }
    }
}

void mergesort(cand array[], int l, int r) {
    if (l < r) {
        int middle = (l + r)/2;
        mergesort(array, l, middle);
        mergesort(array, middle + 1, r);
        merge(array, l, r);
    }
}

int main() {
    int cargos;
    cin >> cargos;

    for (int i = 0; i < cargos; i++) {
        int num_cand;
        int vagas;

        cin >> num_cand >> vagas;
        cand candidato[num_cand];

        for (int j = 0; j < num_cand; j++) {
            candidato[j].coloc = j;

            cin >> candidato[j].nome >> candidato[j].nota >> candidato[j].idade;
        }

        // fazer sort
        mergesort(candidato, 0, num_cand - 1);

        cout << "cargo " << i + 1 << ":" << endl;

        for (int m = 0; m < vagas; m++) {
            if (m >= num_cand) {
                cout << "x" << endl;
            }
            
            else {
                cout << candidato[m].nome << endl;   
            }
        }
    }

    return 0;
}