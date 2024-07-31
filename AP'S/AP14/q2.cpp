#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<vector<int>>& result, vector<int>& weights, vector<int>& values, int i, int j) {
    if (result[i][j] < 0) {
        int value;
        if (j < weights[i]) {
            value = knapsack(result, weights, values, i - 1, j);
        }

        else {
            value = max(knapsack(result, weights, values, i - 1, j), values[i] + knapsack(result, weights, values, i - 1, j - weights[i]));
        }

        result[i][j] = value;
    }

    return result[i][j];
}

int main() {
    int itens, capacity;

    cin >> itens >> capacity;

    vector<int> weights(itens + 1);
    weights[0] = 0;

    vector<int> values(itens + 1);
    values[0] = 0;

    for (int i = 1; i <= itens; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> result(itens + 1, vector<int>(capacity + 1, -1));
    for (int i = 0; i <= itens; i++) {
        result[i][0] = 0;
    }

    for (int i = 0; i <= capacity; i++) {
        result[0][i] = 0;
    }

    knapsack(result, weights, values, itens, capacity);

    for (int i = 0; i < itens + 1; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            cout << result[i][j] << ' ';

            if (j != capacity && result[i][j + 1] < 10 && result[i][j + 1] != -1) {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}