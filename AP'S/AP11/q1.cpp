#include <bits/stdc++.h>

using namespace std;

struct edge{
    int nodeAtual;
    int nextNode;
    int weight;

    bool operator < (const edge& e1)const {
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

    void dijkstra(int start) {
        vector<int> dist(numNode);
        vector<int> parent(numNode);
        edge temp;

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode;
            setMark(i, false);
        }
        
        priority_queue<edge> heap;
        heap.push({start, start, 0});
        dist[start] = 0;

        for (int i = 0; i < numNode; i++) {
            do {
                if (heap.empty()) goto end;

                temp = heap.top();
                heap.pop();
                
            } while (getMark(temp.nextNode));
            
            setMark(temp.nextNode, true);
            parent[temp.nextNode] = temp.nodeAtual;

            for (auto i : adj[temp.nextNode]) {
                if (!getMark(i.first) && dist[i.first] > (dist[temp.nextNode] + weight(i.first, temp.nextNode))) {
                    dist[i.first] = dist[temp.nextNode] + weight(i.first, temp.nextNode);
                    heap.push({temp.nextNode, i.first, dist[i.first]});
                }
            }
        }

        end:

            for (auto i : dist) {
                cout << i << " ";
            }
    }
};

int main() {
    int nodes, edges, search, n1, n2, weight;
    cin >> nodes >> edges >> search;
    Graph graph(nodes);

    while (edges--) {
        cin >> n1 >> n2 >> weight;
        graph.setEdge(n1, n2, weight);
    }

    graph.dijkstra(search);

    return 0;
}