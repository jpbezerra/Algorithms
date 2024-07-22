#include <bits/stdc++.h>

using namespace std;

int knapsack(int numItens, int capacity, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> matrix;
    matrix.resize(numItens + 1, vector<int>(capacity + 1));

    for (int i = 0; i < numItens + 1; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            }
            
            else if (weights[i] <= j) {
                matrix[i][j] = max(matrix[i - 1][j], (values[i] + matrix[i - 1][j - weights[i]]));
            }
            
            else {
                matrix[i][j] = matrix[i - 1][j];                
            }
        }
    }

    return matrix[numItens][capacity];    
};

void setup(int size, int itens) {
    int weight, value;
    int numItens = itens;

    vector<int> weights;
    weights.resize(itens + 1);
    weights[0] = 0;

    vector<int> values;
    values.resize(itens + 1);
    values[0] = 0;

    int i = 1;
    while (itens--) {
        cin >> weight >> value;
        weights[i] = weight;
        values[i] = value;
        i++;
    }
    
    int result = knapsack(numItens, size, weights, values);
    cout << result;
}

int main() {
    int size, itens;

    cin >> size >> itens;

    setup(size, itens);

    return 0;
}