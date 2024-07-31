#include <bits/stdc++.h>

using namespace std;

void coinRow(vector<int>& coins, int size) {
    vector<int> result(size + 1);
    result[0] = 0;
    result[1] = coins[1];

    for (int i = 2; i <= size; i++) {
        result[i] = max(coins[i] + result[i - 2], result[i - 1]);
    }

    cout << result[size] << '\n';

    vector<int> numbers;
    numbers.reserve(size);

    for (int i = size; i >= 0; i--) {
        if (result[i] != result[i - 1]) {
            numbers.push_back(coins[i]);
            i--;
        }
    }

    int temp = numbers.size();
    for (int i = temp - 1; i >= 0; i--) {
        cout << numbers[i];

        if (numbers[i] != numbers[0]) {
            cout << ' ';
        }
    }

    cout << '\n';
}

int main() {
    int cases, size;

    cin >> cases;

    while (cases--) {
        cin >> size;
        vector<int> coins(size + 1);
        coins[0] = 0;

        for (int i = 1; i <= size; i++) {
            cin >> coins[i];
        }

        coinRow(coins, size);
    }

    return 0;
}