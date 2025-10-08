#include <vector>
using namespace std;

class DSU
{
public:
    DSU(int N)
    {
        prefixo.assign(N, 0);
        tamanhoGrupo.assign(N, 1);
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

            if (TamanhoGrupo(a) > TamanhoGrupo(b))
            {
                prefixo[b] = a;
                tamanhoGrupo[a] += TamanhoGrupo(b);
            }
            else if (TamanhoGrupo(b) > TamanhoGrupo(a))
            {
                prefixo[a] = b;
                tamanhoGrupo[b] += TamanhoGrupo(a);
            }
            else
            {
                prefixo[b] = a;
                tamanhoGrupo[a] += TamanhoGrupo(b);
            }
            totalGrupos--;
            maiorGrupo = max(maiorGrupo, tamanhoGrupo[a]);
            maiorGrupo = max(maiorGrupo, tamanhoGrupo[b]);
        }
    }

    int TamanhoGrupo(int i)
    {
        return FindSet(i) == i ? tamanhoGrupo[i] : (tamanhoGrupo[i] = tamanhoGrupo[FindSet(i)]);
    }

    vector<int> prefixo;
    vector<int> tamanhoGrupo;
    int totalGrupos;
    int maiorGrupo;
};