#include <bits/stdc++.h>

/*
    implementar khan, revisar dijkstra, implementar prim, kruskal
    refazer código de grafos
*/

using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;
    vector<bool> mark;
    vector<int> dfsOrder; // opcional
    vector<int> bfsOrder; // opcional
    int numNode;
    int numEdge;

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
    };

    void DFS(int start) {
        dfsOrder.push_back(start);
        // previsit - putting the value on the vector

        setMark(start, true);
        int aux = first(start);

        while (aux < numNode) {
            if (!getMark(aux)) {
                DFS(aux);
            }
            
            aux = next(start, aux);
        }
        
        // posvisit
    };

    void BFS(int start) {
        queue<int> myQueue;
        myQueue.push(start);
        setMark(start, true);

        while (myQueue.size() > 0) {
            start = myQueue.front();
            myQueue.pop();

            bfsOrder.push_back(start);
            // previsit - putting the value on the vector

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
    };

    // instead of string operation we can get int choice, 0 to be BFS and 1 to be DFS or another logic to choose
    void traverse(string operation, int value) {
        if (operation == "BFS") {
            BFS(value);
            return;
        }
        
        DFS(value);
    };

    void dijkstraHelp(vector<int> distance, vector<int> parent, int start) {
        pair<int, int> myPair;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;

        heap.push(make_tuple(start, start, 0));
        distance[start] = 0;

        for (int i = 0; i < numNode && !heap.empty(); i++) {
            do {
                auto temp = heap.top();
                heap.pop();
                myPair = {get<0>(temp), get<1>(temp)};

            } while (getMark(myPair.second));
            
            setMark(myPair.second, true);
            parent[myPair.second] = myPair.first;

            int aux = first(myPair.second);

            while (aux < numNode) {
                if (!getMark(aux) && distance[aux] > (distance[myPair.second] + weight(myPair.second, aux))) {
                    distance[aux] = distance[myPair.second] + weight(myPair.second, aux);
                    heap.push(make_tuple(myPair.second, aux, distance[aux]));
                }

                aux = next(myPair.second, aux);   
            }
        }

        for (auto t: distance) {
            cout << t << " ";
        }
        
        cout << '\n';
    };

    void primHelp(vector<int> distance, vector<int> parent) {
        pair<int, int> myPair;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;

        heap.push(make_tuple(0, 0, 0));
        distance[0] = 0;

        for (int i = 0; i < numNode && !heap.empty(); i++) {
            do {
                auto temp = heap.top();
                heap.pop();
                myPair = {get<0>(temp), get<1>(temp)};

            } while (getMark(myPair.second));
            
            setMark(myPair.second, true);
            parent[myPair.second] = myPair.first;

            int aux = first(myPair.second);

            while (aux < numNode) {
                if (!getMark(aux) && distance[aux] > weight(myPair.second, aux)) {
                    distance[aux] = weight(myPair.second, aux);
                    heap.push(make_tuple(myPair.second, aux, distance[aux]));
                }

                aux = next(myPair.second, aux);   
            }
        }

        for (auto t: distance) {
            cout << t << " ";
        }
        
        cout << '\n';
    }

public:
    Graph(int size) {
        matrix.resize(size, vector<int>(size, 0));
        mark.resize(size);
        dfsOrder.resize(size);
        bfsOrder.resize(size);
        numNode = size;
        numEdge = 0;
    };

    ~Graph() {
        matrix.clear();
        mark.clear();
        dfsOrder.clear();
        bfsOrder.clear();

        cout << "Graph destroyed" << '\n';
    };

    vector<vector<int>> myMatrix() {
        return matrix;
    };

    vector<bool> myMark() {
        return mark;
    };

    int numbNode() {
        return numNode;
    };

    int numbEdge() {
        return numEdge;
    };

    vector<int> dfsVec() {
        return dfsOrder;
    };

    vector<int> bfsVec() {
        return bfsOrder;
    };

    void setEdge(int node1, int node2, int weight) {
        if (weight == 0) {
            cerr << "Weight value is 0" << '\n';
            return;
        }
        
        if (!isEdge(node1, node2)) {
            numEdge++;
        }
        
        matrix[node1][node2] = weight;
        // matrix[node2][node1] = weight <- this is for undirected graphs
    };

    void delEdge(int node1, int node2) {
        if (isEdge(node1, node2)) {
            numEdge--;
        }
        
        matrix[node1][node2] = 0;
        // matrix[node2][node1] = 0 <- this is for undirected graphs
    };

    int weight(int node1, int node2) {
        return matrix[node1][node2];
    };

    void graphTraverse(string operation) {
        for (int i = 0; i < numNode; i++) {
            setMark(i, false);
        }
        
        for (int i = 0; i < numNode; i++) { 
        // we can get a cin here and put int i = cin >> value

            if (!getMark(i)) {
                traverse(operation, i);
            }
        }

        if (operation == "BFS") {
            for (int i = 0; i < bfsOrder.size(); i++) {
                cout << bfsOrder[i] << " ";
            }
            
            bfsOrder.clear();
            return;
        }
        
        for (int i = 0; i < dfsOrder.size(); i++) {
            cout << dfsOrder[i] << " ";
        }

        dfsOrder.clear();
    };

    void dijkstra(int start) {
        vector<int> distance(numNode);
        vector<int> parent(numNode);

        for (int i = 0; i < numNode; i++) {
            distance[i] = -1;
            parent[i] = -1;
            setMark(i, false);
        }

        // fix dijkstrahelp() function
        dijkstraHelp(distance, parent, start);
    };

    void prim() {
        vector<int> distance(numNode);
        vector<int> parent(numNode);

        for (int i = 0; i < numNode; i++) {
            distance[i] = -1;
            parent[i] = -1;
            setMark(i, false);
        }

        primHelp(distance, parent);
    }

    void floydWarshall() {
        vector<vector<int>> distance;
        distance.resize(numNode, vector<int>(numNode, 0));

        for (int i = 0; i < numNode; i++) {
            for (int j = 0; j < numNode; j++) {
                if (i == j) {
                    distance[i][j] = 0;
                }
                
                else if (weight(i, j) != 0) {
                    distance[i][j] = weight(i, j);
                }
                
                else {
                    distance[i][j] = -1; // valor simbólico
                }
            }
        }
        
        for (int k = 0; k < numNode; k++) {
            for (int i = 0; i < numNode; i++) {
                for (int j = 0; j < numNode; j++) {
                    if (distance[i][j] != -1 && distance[k][j] != -1 && distance[i][j] > (distance[i][k] + distance[k][j])) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    };

    bool bellmanFord(int start) {
        vector<vector<int>> dist;
        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
        }
        
        dist[0] = 0;
        for (int i = 0; i < numNode - 1; i++) {
            for (int j = 0; j < numNode; j++) {
                int aux = first(j);

                while (j < numNode) {
                    if (dist[j] > (dist[i] + weight(i, j))) {
                        dist[j] = dist[i] + weight(i, j)
                    }
                    
                    aux = next(j, aux);
                }
            }
        }

        for (int i = 0; i < numNode; i++) {
            int temp = first(i);

            while (temp < numNode) {
                if (dist[temp] > (dist[i] + weight(i, temp))) {
                    // negative cycle detected
                    return true;
                }
            }
        }

        return false;                
    };

    void topoSort(int value, stack<int> myStack) {
        setMark(value, true);
        int aux = first(value);

        while (aux < numNode) {
            if (!getMark(mark, aux)) {
                topoSort(aux, myStack);
            }
            
            aux = next(value, aux);
        }
        
        myStack.push(value);
    };

    void khan() {
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
            // o grafo tem pelo menos dois componentes conexos
            cout << "Fails." << '\n';
            return;
        }

        for (int i; i < result.size(); i++) {
            cout << result[i] + 1 << " ";
        }
        
        cout << '\n';
    }
};

int main() {
    Graph graph(5);

    return 0;
}