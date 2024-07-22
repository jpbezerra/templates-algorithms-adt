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