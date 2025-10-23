#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int, vector<pair<int, int>>> listaArestas;

BFS(int s) {
    vector<int> d(quantidadeNos, INFINITY);
    d[s] = 0;
    
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (pair<int, int> aresta : listaArestas[u]) {
            int v = aresta.first;

            if ()
        }
    }
}