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
    int numEdge;

    bool isEdge(int node1, int node2) {
        return adj[node1].count(node2);
    };

    void setMark(int node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(int node) {
        return mark[node];
    };

    void DFS(int start/*, vector<int>& pre, vector<int>& post*/) {
        // previsit - adicionar os nós em pre-order
        // pre.push_back(start);

        setMark(start, true);

        for (auto i : adj[start]) {
            if (!getMark(i.first)) {
                DFS(i.first /*pre, post*/);
            }
        }

        // posvisit - adicionar os nós em post-order
        // pre.push_back(start);
    };

    void BFS(int start/*, vector<int>& pre, vector<int>& post*/) {
        queue<int> temp; // se mudar para stack vira DFS
        temp.push(start);
        setMark(start, true);

        while (!temp.empty()) {
            int aux = temp.front();
            temp.pop();

            // previsit - adicionar os nós em pre-order
            // pre.push_back(aux);

            for (auto i : adj[aux]) {
                if (!getMark(i.first)) {
                    setMark(i.first, true);
                    temp.push(i.first);
                }
            }

            // posvisit - adicionar os nós em post-order
            // pre.push_back(aux);
        }
    };

    void traverse(const string& oper, int start) {
        vector<int> pre(numNode), post(numNode);
        if (oper == "BFS") {
            BFS(start);
        }

        else {
            DFS(start);
        }
    }

public:
    Graph(int size) {
        adj.assign(size, unordered_map<int, int> {});
        numNode = size;
        numEdge = 0;
    }

    ~Graph() {
        adj.clear();
        mark.clear();
    };

    void setEdge(int node1, int node2, int wt) {
        adj[node1][node2] = wt;
        // adj[node2][node1] = wt; caso for não dirigido
    };

    void delEdge(int node1, int node2) {
        adj[node1][node2] = 0;
        // adj[node2][node1] = 0; caso for não dirigido
    };

    int weight(int node1, int node2) {
        return adj[node1][node2];
        // pode colocar alguma condição caso retorne 0 (o que significa que não há aresta)
    };

    int sum() {
        int total = 0;

        for (auto i: adj) {
            for (auto j: i) {
                total += j.second;
            }
        }

        return total;
    };

    void graphTraverse(const string& oper) {
        for (int i = 0; i < numNode; i++) {
            setMark(i, false);
        }

        for (int i = 0; i < numNode; i++) {
            if (!getMark(i)) {
                traverse(oper, i);
            }
        }
    };

    void topoSort(int start, stack<int>& myStack) {
        setMark(start, true);
        for (int i = 0; i < numNode; i++) {
            if (!getMark(i)) {
                topoSort(i, myStack);
            }
        }

        myStack.push(start);
    };

    void khan() {
        vector<int> inDegree(numNode, 0);
        for (int i = 0; i < numNode; i++) {
            for (int it = 0; i < numNode; i++) {
                if (isEdge(i, it)) {
                    inDegree[it]++;
                }
            }
        }

        /*
            nesse caso heap mínima, mas pode trocar para máxima
            dependendo do contexto (não sei se queue normal funciona)
        */

        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < numNode; i++) {
            if (inDegree[i] == 0) {
                heap.push(i);
            }
        }

        vector<int> result;
        while (!heap.empty()) {
            int temp = heap.top();
            heap.pop();
            result.push_back(temp);

            for (auto i : adj[temp]) {
                inDegree[i.first]--;

                if (inDegree[i.first] == 0) {
                    heap.push(i.first);
                }
            }
        }

        if (result.size() != numNode) {
            // siginifica que o grafo tem pelo menos dois componentes conexos
            cout << "Fails." << '\n';
            return;
        }

        for (auto i : result) {
            cout << i << " ";
        }
    };

    void shortestPath(int start, int dest) {
        for (int i = 0; i < numNode; i++) {
            setMark(i, false);
        }

        vector<int> pred;
        pred.resize(numNode, -1);

        BFS(start);

        if (!getMark(dest)) {
            cout << "There isn't a path between " << start << " and " << dest << '\n';
            return;
        }

        stack<int> myStack;

        while (dest != -1) {
            myStack.push(dest);
            dest = pred[dest];
        }

        int size = myStack.size();
        for (int i = 0; i < size; i++) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
    };

    void dijkstra(int start /*int dest (caso a gente queira saber apenas o peso de ir de um nó para outro)*/) {
        vector<int> dist(numNode);
        vector<int> parent(numNode);

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode + 1;
            setMark(i, false);
        }

        priority_queue<Edge> heap;
        heap.push({start, start, 0});
        dist[start] = 0;

        Edge temp;
        for (int _ = 0; _ < numNode; _++) {
            do {
                if (heap.empty()) {
                    goto end;
                }

                temp = heap.top();
                heap.pop();

            } while (getMark(temp.nodeNext));

            setMark(temp.nodeNext, true);
            parent[temp.nodeNext] = temp.nodeAtual;

            for (auto i : adj[temp.nodeNext]) {
                if (!getMark(i.first) && dist[i.first] > (dist[temp.nodeNext] + weight(i.first, temp.nodeNext))) {
                    dist[i.first] = (dist[temp.nodeNext] + weight(i.first, temp.nodeNext));
                    heap.push({temp.nodeNext, i.first, dist[i.first]});
                }
            }
        }

        end:
            // return dist[dest]; caso queiramos saber o pesor de ir de start -> dest
            for (auto i : dist) {
                cout << i << " "; // distancia de start para cada vértice
            }
    };

    void floydWarshall(/*int start, int dest*/) {
        vector<vector<int>> dist;
        dist.resize(numNode, vector<int>(numNode, 0));

        for (int i = 0; i < numNode; i++) {
            for (int j = 0; j < numNode; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                }

                else if (weight(i, j) != 0) {
                    dist[i][j] = weight(i, j);
                }

                else {
                    dist[i][j] = INT_MAX;
                }
            }
        }


        for (int k = 0; k < numNode; k++) {
            for (int i = 0; i < numNode; i++) {
                for (int j = 0; j < numNode; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > (dist[i][k] + dist[k][j])) {
                        dist[i][j] = (dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        /*
            Caso tenha parâmetros de começo e destino

            if (dist[start][dest] == INT_MAX) {
                cout << "No path between" << start << "and" << dest << '\n';
            }

            else {
                cout << "Path between" << start << "and" << dest << '\n';
            }
        */

        for (int i = 0; i < numNode; i++) {
            for (int j = 0; j < numNode; j++) {
                if (dist[i][j] == INT_MAX) {
                    cout << "No path between" << i << "and" << j << '\n';
                }

                else {
                    cout << "Path between" << i << "and" << j << ", weight: " << dist[i][j] << '\n';
                }
            }
        }
    };

    bool bellmanFord(int start) {
        vector<int> dist;
        dist.resize(numNode);

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
        }

        dist[start] = 0;

        for (int k = 0; k < numNode - 1; k++) {
            for (int i = 0; i < numNode; i++) {
                for (auto j : adj[i]) {
                    if (dist[j.first] > (dist[i] + weight(i, j.first))) {
                        dist[j.first] = (dist[i] + weight(i, j.first));
                    }
                }
            }
        }

        for (int i = 0; i < numNode; i++) {
            for (auto j : adj[i]) {
                if (dist[j.first] > (dist[i] + weight(i, j.first))) {
                        cout << "Negative cycle detected!\n";
                        return true;
                }
            }
        }

        cout << "Negative cycle not detected!\n";
        return false;
    };

    void prim() {
        // int sum = 0; podemos checar a soma da MST

        vector<int> dist(numNode);
        vector<int> parent(numNode);

        for (int i = 0; i < numNode; i++) {
            dist[i] = INT_MAX;
            parent[i] = numNode + 1;
            setMark(i, false);
        }

        priority_queue<Edge> heap;
        heap.push({0, 0, 0});
        dist[0] = 0;

        Edge temp;
        for (int i = 0; i < numNode; i++) {
            do {
                if (heap.empty()) {
                    goto end;
                }

                temp = heap.top();
                heap.pop();

            } while (getMark(temp.nodeNext));

            setMark(temp.nodeNext, true);
            parent[temp.nodeNext] = temp.nodeAtual;

            for (auto i : adj[temp.nodeNext]) {
                if (!getMark(i.first) && dist[i.first] > + weight(i.first, temp.nodeNext)) {
                    dist[i.first] = weight(i.first, temp.nodeNext);
                    heap.push({temp.nodeNext, i.first, dist[i.first]});
                }
            }
        }

        end:
            /*
                Para checar se é uma MST podemos percorrer os nós e checar se algum não foi marcado
            */

           // int great = 0; podemos checar qual a aresta de maior peso da MST
           for (int i = 0; i < numNode; i++) {
                if (!getMark(i)) {
                    cout << "Not a MST\n";
                    return;
                }

            /*
                if (dist[i] > greater) {
                    great = dist[i];
                } atualizando a aresta de maior peso
            */

            /*
                podemos atualizar a soma por aqui
                sum += dist[i];
            */
           }
    };

    void kruskal() {
        Graph result(numNode);
        priority_queue<Edge> heap;

        for (int i = 0; i < numNode; ++i) {
            for (auto j:adj[i]) {
                heap.push({i, j.first, j.second});
            }
        }

        unionFind uf(numNode);
        int aux = numNode;

        while (aux > 1) {
            auto temp = heap.top();
            heap.pop();

            int rt1 = uf.find(temp.nodeAtual);
            int rt2 = uf.find(temp.nodeNext);

            if (rt1 != rt2) {
                uf.merge(rt1, rt2);
                result.setEdge(rt1, rt2, temp.weight);
                aux--;
            }
        }

        /*
            Podemos checar a soma da MST
            return result.sum();
        */
    }
};