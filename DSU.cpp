#include <vector>
using namespace std;

class DSU
{
public:
    DSU(int N)
    {
        prefixo.assign(N, 0);
        rank.assign(N, 1);
        for (int i = 0; i < N; i++)
        {
            prefixo[i] = i;
        }
        totalGrupos = N;
        maiorGrupo = 1;
    }

    int FindSet(int i)
    {
        return prefixo[i] == i ? i : (prefixo[i] = FindSet(prefixo[i]));
    }

    bool SameSet(int i, int j)
    {
        return FindSet(i) == FindSet(j);
    }

    void UnionSet(int i, int j)
    {
        if (!SameSet(i, j))
        {
            int a = FindSet(i);
            int b = FindSet(j);

            if (rank[a] > rank[b])
            {
                prefixo[b] = a;
                rank[a] += rank[b];
            }
            else if (rank[b] > rank[a])
            {
                prefixo[a] = b;
                rank[b] += rank[a];
            }
            else
            {
                prefixo[b] = a;
                rank[a] += rank[b];
            }
            totalGrupos--;
            maiorGrupo = max(maiorGrupo, rank[a]);
            maiorGrupo = max(maiorGrupo, rank[b]);
        }
    }

    int tamanho(int i)
    {
        return prefixo[i] == i ? rank[i] : (rank[i] = rank[prefixo[i]]);
    }

    vector<int> prefixo;
    vector<int> rank;
    int totalGrupos;
    int maiorGrupo;
};