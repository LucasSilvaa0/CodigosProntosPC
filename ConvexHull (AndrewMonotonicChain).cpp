#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct P
{
    ll x, y;
    bool operator<(const P &o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

ll sentidoGiro(const P &a, const P &b, const P &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<P> ConvexHull(vector<P> pontos)
{
    sort(pontos.begin(), pontos.end());

    vector<P> baixo, cima;

    for (auto &p : pontos)
    {
        while (baixo.size() >= 2 && sentidoGiro(baixo[baixo.size() - 2], baixo.back(), p) < 0)
            baixo.pop_back();
        baixo.push_back(p);
    }

    for (ll i = pontos.size() - 1; i >= 0; --i)
    {
        auto &p = pontos[i];
        while (cima.size() >= 2 && sentidoGiro(cima[cima.size() - 2], cima.back(), p) < 0)
            cima.pop_back();
        cima.push_back(p);
    }

    vector<P> forma;
    for (auto &p : baixo)
        forma.push_back(p);
    for (ll i = 1; i + 1 < (ll)cima.size(); ++i)
        forma.push_back(cima[i]);

    return forma;
}