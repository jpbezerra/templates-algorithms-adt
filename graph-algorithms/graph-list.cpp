#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;
    vector<bool> mark;
    int numNode;

    bool isEdge(int node1, int node2) {
        return find(adj[node1].begin(), adj[node1].end(), node2) != adj[node1].end();
    };

    void setMark(int node, bool choice) {
        mark[node] = choice;
    };

    bool getMark(int node) {
        return mark[node];
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
    }

public:
    Graph(int size) {
        adj.reserve(size);
        mark.resize(size);
        numNode = size;
    };

    ~Graph() {
        adj.clear();
        mark.clear();
    };  

    void setEdge(int node1, int node2) {
        adj[node1].push_back(node2);
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
        
        priority_queue<int> q;
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

        for (int i = 0; i < result.capacity(); i++) {
            cout << result[i] << " ";
        }
    }
};
