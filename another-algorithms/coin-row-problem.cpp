#include <bits/stdc++.h>

using namespace std;

void coinRow(int size, vector<int>& coin) {
    vector<int> result(size + 1);
    result[0] = 0;
    result[1] = coin[1];

    for (int i = 2; i <= size; i++) {
        result[i] = max(coin[i] + result[i - 2], result[i - 1]);
    }

    /*
        if we want only the result, we do: 
        return result[coin];    
    */ 

    // getting the chosen size

    vector<int> results;
    results.reserve(size);

    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] != result[i - 1]) {
            results.push_back(i);
            i--;
        }
    }

    int temp = results.size() - 1;
    for (int i = temp; i >= 0; i--) {
        if (i == 0) {
            cout << coin[results[i]] << '=' << result[size] << '\n';
            break;
        }

        cout << coin[results[i]] << '+';
    }
}