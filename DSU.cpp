#include <vector>
using namespace std;

class DSU {
public:
    DSU(int N) {
        prefixo.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N; i++) {
            prefixo[i] = i;
        }
    }

    int FindSet(int i) {
        return prefixo[i] == i ? i : (prefixo[i] = FindSet(prefixo[i]));
    }

    bool SameSet(int i, int j) {
        return FindSet(i) == FindSet(j);
    }

    void UnionSet(int i, int j) {
        if (!SameSet(i, j)) {
            int a = FindSet(i);
            int b = FindSet(j);

            if (rank[a] > rank[b]) {
                prefixo[b] = a;
            } else if (rank[b] > rank[a]) {
                prefixo[a] = b;
            } else {
                prefixo[b] = a;
                rank[a]++;
            }
        }
    }

    vector<int> prefixo;
    vector<int> rank;
};