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