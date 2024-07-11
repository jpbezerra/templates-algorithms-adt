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
}