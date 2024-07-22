#include <bits/stdc++.h>

using namespace std;

void frog(int numStones, int steps, const vector<int>& stone) {
    vector<int> result(numStones, INT_MAX);
    result[0] = 0;

    for (int i = 0; i < numStones; i++) {
        int aux = min(steps, numStones - i - 1);
        
        for (int j = 1; j <= aux; j++) {
            result[i + j] = min(result[i + j], result[i] + abs(stone[i] - stone[i + j]));
        }
    }

    cout << result[numStones - 1];
}

int main() {
    int numStones, steps;

    cin >> numStones >> steps;

    vector<int> stone(numStones);

    for (int i = 0; i < numStones; i++) {
        cin >> stone[i];
    }

    frog(numStones, steps, stone);

    return 0;
}