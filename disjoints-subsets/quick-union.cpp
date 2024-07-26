#include <bits/stdc++.h>

using namespace std;

class unionFind {
private:
    int sets;
    vector<int> ppt;
    vector<int> sizes;
    vector<int> rank;

public:
    unionFind(int size) {
        sets = size;
        ppt.resize(size);
        sizes.resize(size);
        rank.resize(size);

        for (int i = 0; i < size; i++) {
            ppt[i] = i;
            sizes[i] = 1;
        }
    };

    int find(int start) {
        if (ppt[start] != start) {
            ppt[start] = find(ppt[start]);
        }
        
        return ppt[start];
    };

    void merge(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);

        if (root1 == root2) {
            return;
        }

        if (sizes[a] < sizes[b]) {
            swap(a, b);
        }

        else if (sizes[a] == sizes[b]) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
                
            else if (rank[a] == rank[b]) {
                if (a < b) {
                    swap(a, b);
                }
            }
        }

        ppt[b] = a;
        sizes[a] += sizes[b];
        rank[a]++;

        sets--;
    };

    int rankSet(int set) {
        return rank[find(set)];
    };

    int sizeSet(int set) {
        return sizes[find(set)];
    };

    int numbSet() {
        return sets;
    }
};