#include <bits/stdc++.h>

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
        return adj[node1].count(node2);
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
        adj.assign(size, unordered_map<int, int>{});
        numNode = size;
    };

    ~Graph() {
        adj.clear();
        mark.clear();
    };

    void setEdge(int node1, int node2, int wt) {
        if (isEdge(node1, node2)) {
            if (weight(node1, node2) > wt) {
                adj[node1][node2] = wt;
                adj[node2][node1] = wt;
            }
        }

        else {
            adj[node1][node2] = wt;
            adj[node2][node1] = wt;
        }
    };

    void prim() {
        int great = 0;
        vector<int> dist(numNode);
        vector<int> parent(numNode);
        Edge temp;

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode;
            setMark(i, false);
        }

        priority_queue<Edge> heap;
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

            for (auto i : adj[temp.nodeNext]) {
                if (!getMark(i.first) && dist[i.first] > weight(i.first, temp.nodeNext)) {
                    dist[i.first] = weight(i.first, temp.nodeNext);
                    heap.push({temp.nodeNext, i.first, dist[i.first]});
                }
            }
        }

        end:
            for (int i = 0; i < numNode; i++) {
                if (!getMark(i)) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }

                if (dist[i] > great) {
                    great = dist[i];
                }
            }

            cout << great << '\n';
    }
};

int main() {
    int over = false;

    while (!over) {
        int cities, roads, city1, city2, wt;
        cin >> cities >> roads;

        if (cities == 0) {
            over = true;
            break;
        }

        Graph graph(cities);

        for (int i = 0; i < roads; i++) {
            cin >> city1 >> city2 >> wt;
            graph.setEdge(city1, city2, wt);
        }

        graph.prim();
    }

    return 0;
}