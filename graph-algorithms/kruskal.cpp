void kruskal() {
    Graph result(numNode);
    priority_queue<Edge> heap;

    for (int i = 0; i < numNode; i++) {
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
};
