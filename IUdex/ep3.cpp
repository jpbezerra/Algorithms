#include <bits/stdc++.h>

using namespace std;

class Hash {
private:
    int capacity;
    int currSize;
    vector<int> hashTable;
    vector<int> perm;
    vector<int> index;

    int h(int value) {
        int temp = (int) floor((((double) value) / ((double) capacity)));

        return value - (capacity * temp);
    };

    int p(int i) {
        return perm[i];
    }

    int find(int key) {
        int tempKey = h(key);
        int aux = tempKey;
        int i = 1;

        while (index[aux] != INT_MAX && i < 7) {
            if (index[aux] == key) {
                return aux;
            }

            aux = tempKey;
            aux += p(i);
            aux = aux % capacity;
            i++;
        }

        return -1;
    }

public:
    Hash(int size) {
        capacity = size;
        currSize = 0;

        hashTable.resize(size, -1);
        perm.resize(size);
        index.resize(size, INT_MAX);

        perm[0] = 0;
        for (int i = 1; i < size; i++) {
            cin >> perm[i];
        }
    };

    ~Hash() {
        hashTable.clear();
        perm.clear();
        index.clear();
    };

    void insert(int key, int value) {
        if (capacity > currSize && find(key) == -1) {
            int tempKey = h(key);
            int aux = tempKey;
            int i = 1;

            while (index[aux] != INT_MAX) {
                aux = tempKey;
                aux += p(i);
                aux = aux % capacity;
                i++;
            }

            index[aux] = key;
            hashTable[aux] = value;

            currSize++;
        }
    }

    void search(int key) {
        int aux = find(key);

        if (aux == -1) {
            cout << -1 << '\n';
            return;
        }

        cout << aux << " " << hashTable[aux] << '\n';
    }
};


int main() {
    int numb, oper;

    cin >> numb;
    while (numb != 0) {
        Hash dict(numb);
        cin >> oper;

        string operation;
        int key, value;

        for (int i = 0; i < oper; i++) {
            cin >> operation;

            if (operation == "add") {
                cin >> key >> value;
                dict.insert(key, value);
            }

            else {
                cin >> key;
                dict.search(key);
            }
        }

        cin >> numb;
    }

    return 0;
}