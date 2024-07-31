#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
private:
    vector<char> heapArr;
    int capacity;
    int currsize;

    int parent(int idx) {
        return idx / 2;
    };

    void Heapify() {
        for (int i = (currsize / 2); i >= 1; i--) {
            int sup = i;
            char value = heapArr[i];
            bool heap = false;

            while (!heap && 2 * sup <= currsize) {
                int aux = 2 * sup;

                if (aux < currsize) {
                    if (heapArr[aux] < heapArr[aux + 1]) {
                        aux++;
                    }
                }

                if (value >= heapArr[aux]) {
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

    void TopDown() {
        int idx = currsize;
        int idx_parent = parent(idx);

        while (idx > 1 && heapArr[idx_parent] < heapArr[idx]) {
            char sup = heapArr[idx_parent];
            char aux = heapArr[idx];

            heapArr[idx_parent] = aux;
            heapArr[idx] = sup;

            idx = idx_parent;
            idx_parent = parent(idx);
        }
    }

public:
    MaxHeap(int size) {
        heapArr.resize(size + 1);
        capacity = size;
        currsize = 0;
    };

    ~MaxHeap() {
        heapArr.clear();
        capacity = currsize = 0;
    };

    void add(char key) {
        if (currsize >= capacity) {
            cout << "Tamanho máximo atingido!\n";
            return;
        }

        currsize++;
        heapArr[currsize] = key;

        TopDown();
    };

    void maxElement() {
        if (currsize > 0) {
            cout << heapArr[1] << '\n';
            return;
        }

        cout << "Não há elemento no topo.\n";
    };

    char findMax() {
        if (currsize > 0) {
            return heapArr[1];
        }
    };

    int removeMax() {
        if (currsize > 0) {
            char max = findMax();
            char change = heapArr[currsize];

            heapArr[1] = change;
            heapArr[currsize] = max;
            currsize--;

            Heapify();

            return max;
        }

        cout << "Heap vazia!" << '\n';
        return 0; // valor simbólico
    };
};

int main() {
    int maxSize, oper;
    char carac;
    string operation;

    cin >> maxSize >> oper;
    MaxHeap heap(maxSize);

    while (oper--) {
        cin >> operation;

        if (operation == "insert") {
            cin >> carac;
            heap.add(carac);
        }

        else if (operation == "remove") {
            heap.removeMax();
        }

        else {
            heap.maxElement();
        }
    }

    return 0;
}