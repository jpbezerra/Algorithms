#include <bits/stdc++.h>

using namespace  std;

class Hash {
private:
    vector<list<int>> HashTable;
    int maxSize;
    int currSize;

    int hashKey(int value) {
        return value % maxSize;
    };

    int find(int value) {
        int key = hashKey(value);

        for (auto numb: HashTable[key]) {
            if (numb == value) {
                return value;
            }
        }

        return -1;
    }

public:
    Hash(int size) {
        maxSize = size;
        currSize = 0;
        HashTable.assign(size, list<int>{});
    }

    ~Hash() {
        HashTable.clear();
    }

    void insert(int value) {
        if (find(value) == -1) {
            int key = hashKey(value);
            HashTable[key].push_back(value);
        }
    }

    void printTable() {
        for (int i = 0; i < HashTable.size(); i++) {
            cout << i;

            for (auto numb: HashTable[i]) {
                cout << " " << numb;
            }

            cout << '\n';
        }
    }
};

int main() {
    Hash dict(10);

    int oper, numb;
    cin >> oper;

    while (oper--) {
        cin >> numb;
        dict.insert(numb);
    }

    dict.printTable();

    return 0;
}