#include <vector>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<long long> &_A)
    {
        A = _A;
        n = (long long)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    long long left(long long p)
    {
        return p << 1;
    }

    long long right(long long p)
    {
        return (p << 1) + 1;
    }

    void build(long long p, long long L, long long R)
    {
        if (L == R)
        {
            st[p] = L;
        }
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            long long p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    long long rmq(long long p, long long L, long long R, long long i, long long j)
    {
        if (i > R || j < L)
            return -1;
        if (L >= i && R <= j)
            return st[p];
        long long p1 = rmq(left(p), L, (L + R) / 2, i, j);
        long long p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1)
        {
            return p2;
        }
        if (p2 == -1)
        {
            return p1;
        }
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    long long rmq(long long i, long long j)
    {
        return rmq(1, 0, n - 1, i, j);
    }

    void update(long long p, long long L, long long R, long long i, long long val) {
        if (L == R) {
            A[L] = val;
        } else {
            long long mid = (L + R) / 2;
            if (i <= mid)
                update(left(p), L, mid, i, val);
            else
                update(right(p), mid + 1, R, i, val);

            long long p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    
    void update(long long i, long long val) {
        update(1, 0, n - 1, i, val);
    }

    vector<long long> st;
    vector<long long> A;
    long long n;
};
