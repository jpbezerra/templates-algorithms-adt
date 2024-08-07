#include <bits/stdc++.h>

using namespace  std;

class Chess {
private:
    int rowMax, colMax;
    vector<vector<int>> table;
    vector<vector<vector<int>>> results;

    bool valid(int r, int c) {
        for (int i = 0; i < r; i++) {
            if (table[i][c] == 1) {
                return false;
            }
        }

        for (int i = r, j = c; i > -1 && j > -1; i--, j--) {
            if (table[i][j] == 1) {
                return false;
            }
        }

        for (int i = r, j = c; i > -1 && j < colMax; i--, j++) {
            if (table[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    void queens(int l) {
        if (l == rowMax) {
            results.push_back(table);
        }

        else {
            for (int i = 0; i < rowMax; i++) {
                if (valid(l, i)) {
                    table[l][i] = 1;
                    queens(l + 1);
                    table[l][i] = 0;
                }
            }
        }
    }

public:
    Chess() {
        int size;
        cin >> size;

        rowMax = colMax = size;
        table.resize(size, vector<int>(size, 0));
    }

    ~Chess() {
        table.clear();
        results.clear();
    };

    void getSolutions() {
        queens(0);

        int size = results.size();
        cout << size << '\n';

        for (int i = 0; i < size; i++) {
            cout << "\nSol. " << i + 1 << ":\n";

            for (int r = 0; r < rowMax; r++) {
                for (int c = 0; c < colMax; c++) {
                    cout << results[i][r][c] << ' ';
                }

                cout << '\n';
            }
        }
    }
};