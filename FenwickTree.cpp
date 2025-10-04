#include <vector>
using namespace std;

#define LSOne(S) ((S) & -(S))
class FenwickTree
{
public:
    FenwickTree(long long n)
    {
        ft.assign(n + 1, 0);
    }

    long long rsq(long long b)
    {
        long long soma = 0;
        for (; b; b -= LSOne(b))
        {
            soma += ft[b];
        }
        return soma;
    }

    long long rsq(long long a, long long b)
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(long long k, long long v)
    {
        for (; k < ft.size(); k += LSOne(k))
        {
            ft[k] += v;
        }
    }

    vector<long long> ft;
};