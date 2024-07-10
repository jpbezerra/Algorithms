#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heapArr;
    vector<int> heapsortArr;
    int capacity;
    int currsize;

public:
    MinHeap(int size) {
        heapArr.resize(size + 1);
        heapsortArr.resize(size + 1);
        capacity = size;
        currsize = 0;

    };

    ~MinHeap() {
        heapArr.clear();
        capacity = currsize = 0;
    };

    int parent(int idx) {
        return idx / 2;
    };

    void Heapify() {
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

    void TopDown() {
        int idx = currsize;
        int idx_parent = parent(idx);

        while (idx > 1 && heapArr[idx_parent] >= heapArr[idx]) {
            int sup = heapArr[idx_parent];
            int aux = heapArr[idx];

            heapArr[idx_parent] = aux;
            heapArr[idx] = sup;

            idx = idx_parent;
            idx_parent = parent(idx);
        } 
    };

    void add(int key) {
        if (currsize >= capacity) {
            return;
        }
        
        currsize++;
        heapArr[currsize] = key;

        TopDown();
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

            Heapify();

            return max; 
        }

        return 0; // valor simbólico
    };

    void heapsort() {
        int temp = currsize;

        for (int i = 1; i <= temp; i++) {
            heapsortArr[i] = removeMin();    
        }

        currsize = temp;

        TopDown();
    };

    void printHeapSort() {
        int temp_size = currsize;
        int temp = 0;
        int aux = 0;

        for (int i = 1; i < temp_size; i++) {
            temp = removeMin() + removeMin();
            aux += temp;
            add(temp);
        }

        cout << aux << '\n';
    }
};


int main() {
    int number;
    int element;

    cin >> number;

    while (number != 0) {
        MinHeap heap(number);
        int element;

        for (int i = 0; i < number; i++) {
            cin >> element;
            heap.add(element);
        }
        
        heap.heapsort();
        heap.printHeapSort();

        cin >> number;
    }
    
    return 0;
}