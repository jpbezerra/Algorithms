#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& subset, vector<int>& result, int targetSum, int currSum, int i) {
    if (currSum == targetSum) {
        return true;
    }

    if (i == subset.size()) {
        return false;
    }

    result.push_back(subset[i]);
    if (solve(subset, result, targetSum, currSum + subset[i], i + 1)) {
        return true;
    }

    result.pop_back();
    if (solve(subset, result, targetSum, currSum, i + 1)) {
        return true;
    }

    return false;
}

int main() {
    int cases, number, targetSum;

    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cout << "Caso " << i + 1 << ": ";

        cin >> number;

        vector<int> subset(number);
        vector<int> result;
        result.reserve(number);

        for (int j = 0; j < number; j++) {
            cin >> subset[j];
        }

        cin >> targetSum;

        if (!solve(subset, result, targetSum, 0, 0)) {
            cout << "-1";
        }

        else {
            cout << '{';

            int size = result.size();
            for (int j = 0; j < size; j++) {
                cout << result[j];

                if (j != size - 1) {
                    cout << ",";
                }
            }

            cout << '}';
        }

        cout << '\n';
    }

    return 0;
}