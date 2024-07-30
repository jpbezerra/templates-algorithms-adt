#include <bits/stdc++.h>

using namespace std;

class unionFind {
private:
    vector<int> repr;
    vector<list<int>> sets;
    int numSets;

public:
    unionFind(int size) {
        numSets = size;
        repr.resize(size);
        sets.resize(size);

        for (int i = 0; i < size; i++) {
            repr[i] = i;
            sets[i].push_back(i);
        }
    };

    int find(int set) {
        return repr[set];
    };

    void merge(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);

        if (root1 == root2) {
            return;
        }

        /*
            otimização: fazer com que root1 sempre seja a árvore de maior tamanho,
            pois é menos custoso ligar uma árvore menor à uma árvore maior do que o contrário
        */
        
        if (sets[root1].size() < sets[root2].size()) {
            swap(sets[root1], sets[root2]);
        }

        for (auto i : sets[root2]) {
            repr[i] = root1;
            sets[root1].push_back(i);
        }

        sets[root2].clear();
        numSets--;
    };

    int leader(int set) {
        return repr[set];
    };

    list<int> mySet(int set) {
        return sets[set];
    }
};
