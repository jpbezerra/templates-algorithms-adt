struct Edge {
    int nodeAtual;
    int nodeNext;
    int weight;

    bool operator < (const Edge& e1) const {
        return weight > e1.weight;
    }
};

int dijkstra(int start /* int dest (se queremos especificamente o destino)*/) {
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
        for (auto i : dist) {
            cout << i << " ";
        }

        /*
            Se queremos apenas a distância do start para o destino fazemos apenas
            cout << dist[dest] << " ";
        */
}