#include <bits/stdc++.h>
using namespace std;
#define ll long long

//vector<int> dfs_num;
//vector<int, vector<pair<int, int>>> listaArestas; // Se a aresta (u, v) tem peso p, a representação é: listaArestas[u] = pair(v, p);

void DFS(int u, vector<int> dfs_num, vector<vector<pair<int, int>>> listaArestas) {
    dfs_num[u] = 1;

    for (pair<int, int> aresta : listaArestas[u]) {
        int v = aresta.first;
        if (dfs_num[v] == 0) {
            DFS(v);
        }
    }
}