#include <bits/stdc++.h>

using namespace std;

class MinHeap {
private:
    vector<int> heapArr;
    vector<int> heapsortArr;
    int capacity;
    int currsize;

    void BottomUp() {
        for (int i = (currsize / 2); i >= 1; i--) {
            int sup = i;
            int value = heapArr[i];
            bool heap = false;

            while (!heap && 2 * sup <= currsize) {
                int aux = 2 * sup;

                if (aux < currsize) {
                    if (heapArr[aux] >= heapArr[aux + 1]) {
                        aux++;
                    }
                }

                if (value < heapArr[aux]) {
                    heap = true;
                }

                else {
                    heapArr[sup] = heapArr[aux];
                    sup = aux;
                }
            }

            heapArr[sup] = value;
        }
    };

    int findMin() {
        if (currsize > 0) {
            return heapArr[1];
        }

        return 0; // valor simbólico
    };

    int removeMin() {
        if (currsize > 0) {
            int max = findMin();
            int change = heapArr[currsize];

            heapArr[1] = change;
            heapArr[currsize] = max;
            currsize--;

            BottomUp();

            return max;
        }

        return 0; // valor simbólico
    };

    void printHeap() { // meu plano era printar como se fosse uma árvore
        for (int i = 1; i <= currsize; i++) {
            cout << heapArr[i] << " ";
        }

        cout << endl;
    };

    void printHeapSort() {
        for (int i = 1; i < currsize + 1; i++) {
            cout << heapsortArr[i] << " ";
        }

        cout << '\n';
    }

public:
    MinHeap(int size) {
        heapArr.resize(size + 1);
        heapsortArr.resize(size + 1);
        capacity = size;
        currsize = 0;

        for (int i = 1; i < size + 1; i++) {
            cin >> heapArr[i];
            currsize++;
        }

        BottomUp();
    };

    ~MinHeap() {
        heapArr.clear();
        heapsortArr.clear();
        capacity = currsize = 0;
    };

    void heapsort() {
        int temp = currsize;

        for (int i = 1; i <= temp; i++) {
            printHeap();
            heapsortArr[i] = removeMin();
        }

        currsize = temp;

        printHeapSort();

        cout << '\n';
    }
};

int main() {
    int cases, size;

    cin >> cases;

    while (cases--) {
        cin >> size;
        MinHeap heap(size);
        heap.heapsort();
    }

    return 0;
}