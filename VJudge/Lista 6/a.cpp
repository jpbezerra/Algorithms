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
        numNode = size;
        adj.assign(size, unordered_map<int, int>{});
    };

    ~Graph() {
        adj.clear();
        mark.clear();
    };

    void setEdge(int node1, int node2, int weight) {
        adj[node1][node2] = weight;
        adj[node2][node1] = weight;
    };

    int dijkstra(int start, int dest) {
        vector<int> dist(numNode);
        vector<int> parent(numNode);
        Edge temp;

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode;
            setMark(i, false);
        }
        
        priority_queue<Edge> heap;
        heap.push({start, start, 0});
        dist[start] = 0;

        for (int _ = 0; _ < numNode; _++) {
            do {
                if (heap.empty()) goto end;

                temp = heap.top();
                heap.pop();
                
            } while (getMark(temp.nodeNext));
            
            setMark(temp.nodeNext, true);
            parent[temp.nodeNext] = temp.nodeAtual;

            for (auto i : adj[temp.nodeNext]) {
                if (!getMark(i.first) && dist[i.first] > (dist[temp.nodeNext] + weight(i.first, temp.nodeNext))) {
                    dist[i.first] = dist[temp.nodeNext] + weight(i.first, temp.nodeNext);
                    heap.push({temp.nodeNext, i.first, dist[i.first]});
                }
            }
        }

        end:
            return dist[dest];
    }
};

int main() {
    int cases, numNode, edges, start, dest, server1, server2, weight;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> numNode >> edges >> start >> dest;
        Graph graph(numNode);

        for (int j = 0; j < edges; j++) {
            cin >> server1 >> server2 >> weight;
            graph.setEdge(server1, server2, weight);
        }

        int result = graph.dijkstra(start, dest);

        cout << "Case #" << i + 1 << ": "; 

        if (result == INT_MAX) {
            cout << "unreachable\n";
        }
        
        else {
            cout << result << '\n';
        }
    }

    return 0;
}
