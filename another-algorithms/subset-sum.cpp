#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& subset, vector<int>& result, int targetSum, int currSum, int i) {
    if (currSum == targetSum) {
        return true;
    }

    if (i == subset.size()) {
        return false;
    }

    result.push_back(subset[i]);
    if (solve(subset, result, targetSum, currSum + subset[i], i + 1)) {
        return true;
    }

    result.pop_back();
    if (solve(subset, result, targetSum, currSum, i + 1)) {
        return true;
    }

    return false;
}