struct Edge {
    int nodeAtual;
    int nodeNext;
    int weight;

    bool operator < (const Edge& e1) const {
        return weight > e1.weight;
    }
};

int prim() {
    // int sum = 0; guardar a soma dos pesos da mst
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
        // sum += dist[temp.nodeNext]; somando os pesos

        for (auto i : adj[temp.nodeNext]) {
            if (!getMark(i.first) && dist[i.first] > weight(i.first, temp.nodeNext)) {
                dist[i.first] = weight(i.first, temp.nodeNext);
                heap.push({temp.nodeNext, i.first, dist[i.first]});
            }
        }
    }

    end:
        // return sum; pode retornar esse peso

        /*
            Para checar se é uma MST podemos iterar sobre os nós e checar se todos estão marcados
            se algum não tiver marcado é porque não dá pra ter uma MST com todos os nós do grafo

            Podemos checar também a aresta mais custosa iterando sobre o array de distâncias
        */
       
        return;
}