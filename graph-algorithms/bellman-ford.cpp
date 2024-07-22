bool bellmanFord(int start) {
    vector<int> dist;
    dist.resize(numNode);

    for (int i = 0; i < numNode; i++) {
        dist[i] = INT_MAX;
    }
        
    dist[start]  0;

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
            if (dist[j] > (dist[i] + weight(i, j))) {
                cout << "Negative cycle detected!\n";
                return true;
            }
        }
    }

    cout << "Negative cycle not detected!\n";
    return false;                
};