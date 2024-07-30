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
        /*
            otimização: compressão de caminhos
        */

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

        // queremos que o 'a' seja o conjunto maior e o 'b' seja o conjunto menor

        /*
            otimização: unir baseado no tamanho dos conjuntos
        */

        if (sizes[a] < sizes[b]) {
            swap(a, b);
        }

        else if (sizes[a] == sizes[b]) {
            /*
                otimização: unir baseado nos ranques dos conjuntos
            */

            if (rank[a] < rank[b]) {
                swap(a, b);
            }
                
            else if (rank[a] == rank[b]) {
                /*
                    otimização: unir baseado em ordenação
                    (nesse caso, o menor número é juntado ao maior número)
                */

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
