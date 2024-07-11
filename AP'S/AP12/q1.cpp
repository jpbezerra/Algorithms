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

    void setEdge(int node1, int node2, int weight) {
        adj[node1][node2] = weight;
        adj[node2][node1] = weight;
    };

    int prim() {
        int sum = 0;
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
            sum += dist[temp.nodeNext];

            for (auto i : adj[temp.nodeNext]) {
                if (!getMark(i.first) && dist[i.first] > weight(i.first, temp.nodeNext)) {
                    dist[i.first] = weight(i.first, temp.nodeNext);
                    heap.push({temp.nodeNext, i.first, dist[i.first]});
                }
            }
        }

        end:
            return sum;
    }
};

int main() {
    int nodes, edges, node1, node2, wt;
    cin >> nodes >> edges;
    Graph graph(nodes);

    for (int i = 0; i < edges; i++) {
        cin >> node1 >> node2 >> wt;
        graph.setEdge(node1, node2, wt);
    }

    int result = graph.prim();

    cout << result << '\n';
}