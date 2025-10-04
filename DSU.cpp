#include <vector>
using namespace std;

class DSU
{
public:
    DSU(long long N)
    {
        prefixo.assign(N, 0);
        rank.assign(N, 0);
        for (long long i = 0; i < N; i++)
        {
            prefixo[i] = i;
        }
    }

    long long FindSet(long long i)
    {
        return prefixo[i] == i ? i : (prefixo[i] = FindSet(prefixo[i]));
    }

    bool SameSet(long long i, long long j)
    {
        return FindSet(i) == FindSet(j);
    }

    void UnionSet(long long i, long long j)
    {
        if (!SameSet(i, j))
        {
            long long a = FindSet(i);
            long long b = FindSet(j);

            if (rank[a] > rank[b])
            {
                prefixo[b] = a;
            }
            else if (rank[b] > rank[a])
            {
                prefixo[a] = b;
            }
            else
            {
                prefixo[b] = a;
                rank[a]++;
            }
        }
    }

    vector<long long> prefixo;
    vector<long long> rank;
};