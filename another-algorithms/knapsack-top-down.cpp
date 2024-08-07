#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<vector<int>>& result, vector<int>& weights, vector<int>& values, int i, int j) {
    if (result[i][j] < 0) {
        int value;
        if (j < weights[i]) {
            value = knapsack(result, weights, values, i - 1, j);
        }

        else {
            value = max(knapsack(result, weights, values, i - 1, j), values[i] + knapsack(result, weights, values, i - 1, j - weights[i]));
        }

        result[i][j] = value;
    }

    return result[i][j];
}