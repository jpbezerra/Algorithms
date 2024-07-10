#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

class Hash {
private:
    int capacity;
    int *HashTable;
    int *index;
    int *perm;

    int HashKey(int value) {
        int temp = (int) floor((((double) value) / ((double) capacity)));

        return value - (capacity * temp);
    }

    int PseudoRandomProbing(int value) {
        return perm[value - 1];
    }

public:
    Hash(int size) {
        capacity = size;

        HashTable = (int*)malloc(size * sizeof(int));
        perm = (int*)malloc(size * sizeof(int));
        index = (int*)malloc(size * sizeof(int));

        int element;

        for (int i = 0; i < capacity; i++) {
            HashTable[i] = -1;
            index[i] = -1;
            

            if (i != capacity - 1) {
                cin >> element;
                perm[i] = element;
            }
        }
        
    };
    
    ~Hash() {
        free(HashTable);
        free(perm);
    };

    void insert(int key, int value) {
        int hold = key;
        key = HashKey(key);

        if (HashTable[key] == -1) {
            HashTable[key] = value;
            index[key] = hold;
            return;
        }

        int sup = 0;
        while (HashTable[key] != -1 && sup != capacity - 1) {
            sup++;
            int curr = PseudoRandomProbing(sup);
            key = (key + curr) % capacity;
        }

        if (sup != capacity - 1) {
            HashTable[key] = value;
            index[key] = hold;
        }
    }

    void search(int key) {
        int hold = key;
        bool right = false;
        key = HashKey(key);

        if (HashTable[key] == -1) {
            cout << "-1" << endl;
            return;
        }

        for (int i = 0; i < capacity; i++) {
            if (index[i] == hold) {
                cout << i << " " << HashTable[i] << endl;
                right = true;
            }
        }
        
        if (!right) {
            cout << "-1" << endl;
        }
    }
};


int main() {
    bool running = true;

    while (running) {
        int number;
        scanf("%d", &number);

        if (number > 0) {
            int j = 1;
            Hash dict(number);

            int cases;

            scanf("%d", &cases);

            if (cases != 0) {
                string operation;
                int key;
                int value;

                for (int i = 0; i < cases; i++) {
                    cin >> operation;

                    if (operation == "add") {
                        cin >> key >> value;

                        dict.insert(key, value);
                    }
                        
                    else if (operation == "find") {
                        cin >> key;

                        dict.search(key);
                    }
                }
            }
        }  

        else {
            running = false;
        }
    }

    return 0;
}