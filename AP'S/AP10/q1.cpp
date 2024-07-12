#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;
    vector<bool> mark;
    int numNode;
    int numEdge;

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

    bool isEdge(int node1, int node2) {
        return (matrix[node1][node2] != 0);
    };

    void setMark(int node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(int node) {
        return mark[node];
    };

    void DFS(int start) {
        cout << start << " ";
        //previsit

        setMark(start, true);
        int aux = first(start);

        while (aux < numNode) {
            if (!getMark(aux)) {
                DFS(aux);
            }
            
            aux = next(start, aux);
        }
        
        //posvisit
    };

    void BFS(int start) {
        queue<int> myQueue;
        myQueue.push(start);
        setMark(start, true);

        while (myQueue.size() > 0) {
            start = myQueue.front();
            myQueue.pop();

            cout << start << " ";
            //previsit

            int aux = first(start);

            while (aux < numNode) {
                if (!getMark(aux)) {
                    setMark(aux, true);
                    myQueue.push(aux);
                }
                
                aux = next(start, aux);
            }
            
            // posvisit
        }   
    }

    void traverse(string operation, int value) {
        if (operation == "BFS") {
            BFS(value);
            return;
        }
        
        DFS(value);
    }

public:
    Graph(int size) {
        matrix.resize(size, vector<int>(size, 0));
        mark.resize(size);
        numNode = size;
        numEdge = 0;
    };

    ~Graph() {
        matrix.clear();
        mark.clear();
    };

    void setEdge(int node1, int node2, int weight) {
        if (weight == 0) {
            cerr << "weight is zero" << '\n';
            return;
        }
        
        if (!isEdge(node1, node2)) {
            numEdge++;
        }
        
        matrix[node1][node2] = weight;
        matrix[node2][node1] = weight;
    };

    void graphTraverse(string operation) {
        for (int i = 0; i < numNode; i++) {
            setMark(i, false);
        }

        int value;
        cin >> value;
        
        for (int i = value; i < numNode; i++) {
            if (!getMark(i)) {
                traverse(operation, i);
            }
        }
    }
};

int main() {
    int nodes;
    cin >> nodes;

    Graph graph(nodes);

    int operations;
    cin >> operations;

    string oper;
    int value1;
    int value2;

    for (int j = 0; j < operations; j++) {
        cin >> oper;

        if (oper == "add") {
            cin >> value1 >> value2;

            graph.setEdge(value1, value2, 1);
        }
        
        else {
            graph.graphTraverse(oper);
            cout << '\n';
        }
    }
    
    return 0;
}
