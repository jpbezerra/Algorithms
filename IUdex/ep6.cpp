#include <bits/stdc++.h>

/*
 * grafo direcionado
 */

using namespace std;

struct Edge {
    int nodeAtual;
    int nodeNext;
    int weight;

    bool operator < (const Edge& e1) const {
        return weight > e1.weight;
    }
};

class Graph {
private:
    vector<unordered_map<int, int>> adj;
    unordered_map<int, bool> mark;
    int numNode;

    bool isEdge(int node1, int node2) {
        return adj[node1].count(node2) != 0;
    };

    void setMark(int node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(int node) {
        return mark[node];
    };

    int weight(int node1, int node2) {
        if (isEdge(node1, node2)) {
            return adj[node1][node2];
        }

        return 0;
    }

public:
    Graph(int size) {
        adj.assign(size, unordered_map<int, int> {});
        numNode = size;
    };

    ~Graph() {
        adj.clear();
        mark.clear();
        numNode = 0;
    }

    void setEdge(int node1, int node2, int wt) {
        adj[node1][node2] = wt;
        adj[node2][node1] = wt;
    };

    int prim() {
        vector<int> dist(numNode);
        vector<int> parent(numNode);

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode;
            setMark(i, false);
        }

        priority_queue<Edge> heap;
        Edge temp;

        heap.push({0, 0, 0});
        dist[0] = 0;

        for (int i = 0; i < numNode; i++) {
            do {
                if (heap.empty()) goto end;

                temp = heap.top();
                heap.pop();

            } while (getMark(temp.nodeNext));

            setMark(temp.nodeNext, true);
            parent[temp.nodeNext] = temp.nodeAtual;

            for (auto j : adj[temp.nodeNext]) {
                if (!getMark(j.first) && dist[j.first] > weight(temp.nodeNext, j.first)) {
                    dist[j.first] = weight(temp.nodeNext, j.first);
                    heap.push({temp.nodeNext, j.first, dist[j.first]});
                }
            }
        }

        end:
            int sum = 0;
            for (auto i : dist) {
                sum += i;
            }

            return sum;
    }
};

int main() {
    int nodes, edges, node1, node2, wt, numCase;

    numCase = 1;

    bool over = false;

    while (!over) {
        cin >> nodes >> edges;

        if (nodes == 0 && edges == 0) {
            over = true;
        }

        else {
            Graph graph(nodes);

            while (edges--) {
                cin >> node1 >> node2 >> wt;
                graph.setEdge(node1, node2, wt);
            }

            int result = graph.prim();

            cout << "Caso " << numCase << ": " << result << '\n';
            numCase++;
        }
    }

    return 0;
}