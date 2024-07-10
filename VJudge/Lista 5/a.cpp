#include <bits/stdc++.h>

using namespace std; 

class Graph {
private:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, pair<string, int>> pred;
    unordered_map<string, bool> mark;

    bool isEdge(const string& node1, const string& node2) {
        return find(adj[node1].begin(), adj[node1].end(), node2) != adj[node1].end();
    };

    void setMark(const string& node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(const string& node) {
        return mark[node];
    };

    void BFS(const string& start) { 
        queue<string> myQueue;
        myQueue.push(start);
        setMark(start, true);

        pred[start] = {"", 0};

        while (!myQueue.empty()) {
            string temp = myQueue.front();
            myQueue.pop();

            for (auto i : adj[temp]) {
                if (!getMark(i)) {
                    setMark(i, true);
                    myQueue.push(i);
                    pred[i] = {temp, pred[temp].second + 1};
                }
            }
        }
    }

public:
    Graph() {};

    ~Graph() {
        adj.clear();
        mark.clear();
    };

    void setEdge(const string& node1, const string& node2) {
        if (!isEdge(node1, node2)) {
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
    };

    void shortestPath() { 
        BFS("Ahmad");

        set<pair<int, string>> result;
        int aux = pred.size() + 1;

        for (auto i: adj) {
            if (pred.find(i.first) == pred.end()) {
                result.insert({aux, i.first});
            }

            else {
                result.insert({pred[i.first].second, i.first});
            }
        } 

        cout << result.size() << '\n';

        for (auto i : result) {
            if (i.first == aux) {
                cout << i.second << " undefined" << '\n';
            }

            else {
                cout << i.second << " " << i.first << '\n';
            }
        }
    }
};

int main() {
    int cases, size;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> size;
        Graph graph;

        string p1, p2, p3;

        for (int j = 0; j < size; j++) {
            cin >> p1 >> p2 >> p3;
            graph.setEdge(p1, p2);
            graph.setEdge(p1, p3);
            graph.setEdge(p2, p3);
        }

        graph.shortestPath();
    }

    return 0;
}