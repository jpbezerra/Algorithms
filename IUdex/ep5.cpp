/*
    grafo não dirigido e não ponderado
*/
#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<bool> mark;
    vector<int> pred;
    int numNode;

    bool isEdge(int node1, int node2) {
        return adj[node1][node2] != 0;
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
    };

    void clearMark() {
        for (int i = 0; i < numNode; i++) {
            setMark(i, false);
        }
    };

    void resetPred() {
        for (int i = 0; i < numNode; i++) {
            pred[i] = -1;
        }
    }

    void BFS(int start, int destination) {
        queue<int> myQueue;
        myQueue.push(start);
        setMark(start, true);

        while (!myQueue.empty()) {
            start = myQueue.front();
            myQueue.pop();

            int aux = first(start);

            while (aux < numNode) {
                if (!getMark(aux)) {
                    setMark(aux, true);
                    myQueue.push(aux);
                    pred[aux] = start;

                    if (aux == destination) {
                        return;
                    }
                }
                
                aux = next(start, aux);
            }
        }
    }

public:
    Graph(int size) {
        adj.resize(size, vector<int>(size, 0));
        mark.resize(size);
        pred.resize(size, -1);
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

    void shortestPath(int start, int destination) {
        clearMark();
        resetPred();
        BFS(start, destination);

        if (!getMark(destination)) {
            cout << -1;
            return;
        }

        stack<int> myStack;

        while (destination != -1) {
            myStack.push(destination);
            destination = pred[destination];
        }
        
        cout << myStack.top();
        myStack.pop();
        
        int size = myStack.size();
        for (int i = 0; i < size; i++) {
            cout << " " << myStack.top();
            myStack.pop();
        }
    }   
};

int main() {
    int cases, nodes, edges, questions, node1, node2;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cout << "Caso " << i + 1 << '\n';
        cin >> nodes >> edges;

        Graph graph(nodes);

        for (int j = 0; j < edges; j++) {
            cin >> node1 >> node2;
            graph.setEdge(node1, node2, 1);
        }
        
        cin >> questions;
        for (int i = 0; i < questions; i++) {
            cin >> node1 >> node2;
            graph.shortestPath(node1, node2);

            cout << '\n';
        }
    }    

    return 0;
}