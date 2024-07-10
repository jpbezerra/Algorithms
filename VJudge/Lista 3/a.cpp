#include <iostream>
#include <string>

using namespace std;

class Hash {
private:
    int capacity; 
    int currsize;
    string *HashTable;
    int *probTable;

    /*
        capacity - capacidade máxima da HashTable
        currsize - quantos elementos estão na HashTable atual
    */

    int Hashkey(string word) {
        int count = 0;

        // count é uma variável auxiliar para guardar os valores da iteração com as letras da palavra

        for (int i = 0; i < (int) word.length(); i++) {
            count += word[i] * (i + 1);
        }
        
        return abs((count * 19)) % 101; // -> chave
    }

public:
    Hash(int size) {
        capacity = size;
        currsize = 0;

        HashTable = new string[size];
        probTable = new int[19];
        // alocando a memória

        for (int i = 0; i < size; i++) {
            HashTable[i] = "emptyJOAOPEDRO"; // declarando todos os espaços como vazios
        }

        for (int i = 1; i <= 19; i++) {
            probTable[i - 1] = (i * i) + (23 * i);
        }
    }

    ~Hash() {
        delete[] HashTable; // liberando a memória pra não dar stack overflow e afins
        delete[] probTable;
    }

    int find(string word) { 
        int sup = 1; 

        // variável de suporte que guarda o valor de quantas iterações aconteceram no do-while
        // como pode-se fazer 20 iterações (sup = 0, ... 19)

        int key = Hashkey(word);
        int currKey = key;

        while (sup < 20 && HashTable[currKey] != "emptyJOAOPEDRO") {
            if (HashTable[currKey] == word) {
                return currKey;
            }

            currKey = (key + probTable[sup - 1]) % 101;
            sup++;
        }

        return -1;

        /* 
            se dentre essas 20 iterações encontramos um lugar vazio então retornamos -1
        */ 
    }

    void insert(string word) {
        int numb_find = find(word); // variável que recebe o return de find(word)
        if (currsize < capacity && numb_find == -1) {
            /*
                currsize <= capacity: enquanto ainda houver capacidade na minha HashTable
                numb_find == -1: se dentro de 20 iterações existir um espaço vazio
            */

            int sup = 1; 
            // variável de suporte com funcionamento idêntico que nem a variável do find

            int key = Hashkey(word);
            int currKey = key;

            while (sup < 20 && HashTable[currKey] != "emptyJOAOPEDRO" && HashTable[key] != "deletedJOAOPEDRO") {
                currKey = (key + probTable[sup - 1]) % 101;
                sup++;
            }

            if (sup != 20) {
                HashTable[currKey] = word;
                currsize++;
            }
        }
    }

    void deletion(string word) { 
        int numb_find = find(word);

        if (numb_find != -1) {
            HashTable[numb_find] = "deletedJOAOPEDRO";
            currsize--;
        }
    }

    void PrintTable() { // um print simples da HashTable + currsize
        cout << currsize << endl;
        for (int i = 0; i < capacity; i++) {
            if (HashTable[i] != "emptyJOAOPEDRO" && HashTable[i] != "deletedJOAOPEDRO") {
                cout << i << ':' << HashTable[i] << endl;
            }
        }
    }
    
    void clear() {
        currsize = 0;

        // reiniciando a HashTable e definindo currsize = 0

        for (int i = 0; i < capacity; i++) {
            HashTable[i] = "emptyJOAOPEDRO";
        }
    }
};

int main() {
    int cases;
    scanf("%d", &cases);

    // quantos casos vão existir

    int operations;
    Hash dict(101);

    for (int i = 0; i < cases; i++) {
        
        scanf("%d", &operations);
        // quantas operações em cada caso

        string phrase;
        string oper; // ADD ou DEL
        string word; 

        for (int i = 0; i < operations; i++) {
            cin >> phrase;

            oper = phrase.substr(0, 3);
            // função pra pegar a palavra até chegar o ':' e atribui à oper

            word = phrase.substr(4);
            // função pra pegar a palavra até chegar o '\n' e atribui à word

            if (oper == "ADD") {
                dict.insert(word);
            }

            else if (oper == "DEL") {
                dict.deletion(word);
            }
        }

        dict.PrintTable(); // printar a HashTable quando acabar todas as operações de um caso
        dict.clear(); // limpar a tabela quando acabar todas as operações de um caso
    }  

    return 0;
}