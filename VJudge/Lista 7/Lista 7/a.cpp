#include <bits/stdc++.h>

using namespace std;

class Chess {
private:
    vector<vector<char>> table;
    vector<vector<bool>> mark;
    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    pair<int, int> start;
    int rowLimit;
    int maxSquares = 0;
    int visitSquares = 0;

    bool valid(int r, int c) {
        if (r < 0 || r >= rowLimit || c < 0 || c >= 10) return false;

        return table[r][c] == 'O';
    }

    void knight(int r, int c, int count) {
        mark[r][c] = true;

        for (int i = 0; i < 8; i++) {
            int tempR = r + moves[i].first;
            int tempC = c + moves[i].second;

            if (valid(tempR, tempC) && !mark[tempR][tempC]) {
                knight(tempR, tempC, count + 1);
            }
        }

        mark[r][c] = false;

        if (count > visitSquares) {
            visitSquares = count;
        }
    }

public:
    Chess(int lines) {
        table.resize(lines, vector<char>(10, 'X'));
        mark.resize(lines, vector<bool>(10, false));

        rowLimit = lines;

        int skips, squares;
        for (int i = 0; i < lines; i++) {
            cin >> skips >> squares;

            if (i == 0) {
                start = {i, skips};
            }

            for (int j = 0; j < squares; j++) {
                table[i][j + skips] = 'O';
                maxSquares++;
            }
        }
    };

    ~Chess() {};

    int unvisited() {
        knight(start.first, start.second, 1);

        return maxSquares - visitSquares;
    }
};

int main() {
    int lines;
    int index = 1;

    while (true) {
        cin >> lines;

        if (lines == 0) break;
        Chess chess(lines);

        int result = chess.unvisited();

        if (result == 1) {
            cout << "Case " << index << ", " << result << " square can not be reached.\n";
        }

        else {
            cout << "Case " << index << ", " << result << " squares can not be reached.\n";
        }

        index++;
    }
}