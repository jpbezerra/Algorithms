#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;
    vector<bool> mark;
    int numNode;

    bool isEdge(int node1, int node2) {
        return (matrix[node1][node2] != 0);
    };

    int first(int node) {
        for (int i = 0; i < numNode; i++) {
            if (isEdge(node, i)) {
                return i;
            }
        }
        
        return numNode;
    };

    int next(int node1, int node2) {
        for (int i = node2 + 1; i < numNode; i++) {
            if (isEdge(node1, i)) {
                return i;
            }
        }
        
        return numNode;
    };

    void setMark(int node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(int node) {
        return mark[node];
    }

public:
    Graph(int size) {
        matrix.resize(size, vector<int>(size, 0));
        mark.resize(size);
        numNode = size;
    };

    ~Graph() {
        matrix.clear();
        mark.clear();
    };

    void setEdge(int node1, int node2, int weight) {
        matrix[node1][node2] = weight;
    };

    void topoSort() {
        vector<int> inDegree(numNode, 0);
        for (int i = 0; i < numNode; i++) {
            for (int it = 0; it < numNode; it++) {
                if (isEdge(i, it)) {
                    inDegree[it]++;
                }
            }
        }
        
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int node = q.top();
            q.pop();
            result.push_back(node);

            for (int it = 0; it < numNode; it++) {
                if (isEdge(node, it)) {
                    inDegree[it]--;

                    if (inDegree[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }
        
        if (result.size() != numNode) {
            cout << "Sandro fails." << '\n';
            return;
        }

        for (int i; i < result.size(); i++) {
            cout << result[i] + 1 << " ";
        }
        
        cout << '\n';
    }
};

int main() {
    int number;
    cin >> number;

    Graph graph(number);

    int operations;
    cin >> operations;

    int node1;
    int node2;

    for (int i = 0; i < operations; i++) {
        cin >> node1 >> node2;
        graph.setEdge(node1 - 1, node2 - 1, 1);
    }

    graph.topoSort();

    return 0;
}