#include <bits/stdc++.h>

using namespace std;

/*
 *  x - treasure
 *  @ - entrance/exit
 *  # - walls
 *  s - spikes
 */

class Maze {
private:
    vector<vector<char>> maze;
    vector<vector<bool>> mark;
    vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    pair<int, int> entrance;
    bool treasure = false;
    int numSpikes, spikes, maxR, maxC;

    bool valid(int r, int c) {
        if (r < 0 || r >= maxR || c < 0 || c >= maxC) return false;
        return (maze[r][c] != '#');
    }

public:
    Maze() {
        cin >> maxR >> maxC >> numSpikes;
        maze.resize(maxR, vector<char>(maxC));
        mark.resize(maxR, vector<bool>(maxC));
        spikes = 0;

        for (int i = 0; i < maxR; i++) {
            for (int j = 0; j < maxC; j++) {
                cin >> maze[i][j];

                if (maze[i][j] == '@') entrance = {i, j};
            }
        }
    };

    ~Maze() {
        maze.clear();
        moves.clear();
    };

    void backtracking(int r, int c) {
        mark[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int tempR = r + moves[i].first;
            int tempC = c + moves[i].second;

            if (valid(tempR, tempC) && !mark[tempR][tempC]) {

                if (maze[tempR][tempC] == 's') spikes += 2;
                
                if (maze[tempR][tempC] == 'x') {
                    treasure = true;
                    return;
                }
                
                backtracking(tempR, tempC);
            }
        }

        mark[r][c] = false;
    };

    void result() {
        backtracking(entrance.first, entrance.second);

        if (!treasure || spikes > numSpikes) {
            cout << "IMPOSSIBLE";
        }

        else if (treasure && numSpikes >= spikes) {
            cout << "SUCCESS";
        }
    }
};

int main() {
    Maze maze;

    maze.result();

    return 0;
}
