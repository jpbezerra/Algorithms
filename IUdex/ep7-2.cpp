#include <bits/stdc++.h>

using namespace std;

void coinRow(int coins, vector<int>& coin) {
    vector<int> result(coins + 1);
    result[0] = 0;
    result[1] = coin[1];

    for (int i = 2; i <= coins; i++) {
        result[i] = max(coin[i] + result[i - 2], result[i - 1]);
    }

    vector<int> results;
    results.reserve(coins);

    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] != result[i - 1]) {
            results.push_back(i);
            i--;
        }
    }

    for (int i = results.size() - 1; i >= 0; i--) {
        if (i == 0) {
            cout << coin[results[i]] << '=' << result[coins] << '\n';
            break;
        }

        if (coin[results[i]] != 0) {
            cout << coin[results[i]] << '+';
        }
    }
}

int main() {
    int cases, coins;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cout << "Caso " << i + 1 << ": ";

        cin >> coins;

        if (coins == 0) {
            cout << "0=0" << '\n';
        }

        else {
            vector<int> coin(coins + 1);
            coin[0] = 0;

            for (int j = 1; j <= coins; j++) {
                cin >> coin[j];
            }

            coinRow(coins, coin);
        }
    }

    return 0;
}
