#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int itens, int capacity) {
    vector<vector<int>> result(itens + 1, vector<int>(capacity + 1, -1));

    for (int i = 0; i < itens; i++) {
        for (int j = 0; j < capacity; j++) {
            if (i == 0 || j == 0) {
                result[i][j] = 0;
            }

            else if (weights[i] <= j) {
                result[i][j] = max(result[i - 1][j], values[i] + result[i - 1][j - weights[i]]);
            }

            else {
                result[i][j] = result[i - 1][j];
            }
        }
    }

    return result[itens][capacity];
}