#include <bits/stdc++.h>

using namespace std;

class Hash {
private:
    int capacity;
    int currSize;
    vector<string> HashTable;

    int hashKey(string& word) {
        int count = 0;

        for (auto carac: word) {
            count += carac;
        }

        return count % capacity;
    }

    int find(string& word) {
        int key = hashKey(word);

        while (HashTable[key] != "") {
            if (HashTable[key] == word) {
                return key;
            }

            key++;
            key = key % capacity;
        }

        return -1;
    }

public:
    Hash(int size) {
        capacity = size;
        currSize = 0;
        HashTable.resize(size, "");
    ;}

    ~Hash() {
        HashTable.clear();
    }

    void insert(string& word) {
        if (capacity > currSize && find(word) == -1) {
            int key = hashKey(word);

            while (HashTable[key] != "") {
                key++;
                key = key % capacity;
            }

            HashTable[key] = word;
        }
    };

    void remove(string& word) {
        int key = find(word);
        HashTable[key] = "";
    }

    void search(string& word) {
        cout << word << " " << find(word) << '\n';
    }
};

int main() {
    int oper;
    string operation, word;

    cin >> oper;

    Hash dict(oper);

    while (operation != "fim") {
        cin >> operation >> word;

        if (operation == "add") {
            dict.insert(word);
        }

        else if (operation == "rmv") {
            dict.remove(word);
        }

        else if (operation == "sch") {
            dict.search(word);
        }
    }

    return 0;
}