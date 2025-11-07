#include <bits/stdc++.h>
using namespace std;
#define ll long long

int Dijkstra(vector<vector<pair<int, int>>> &grafo, int inicio, int fim, int quantidadeNos)
{
    vector<int> custos(quantidadeNos, -1);
    custos[inicio] = 0;
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, inicio});
    while (!heap.empty())
    {
        pair<int, int> CustoNo = heap.top();
        int custoAtual = CustoNo.first;
        int noAtual = CustoNo.second;
        heap.pop();

        for (pair<int, int> par : grafo[noAtual])
        {
            if (custos[par.first] != -1)
            {
                if (custos[noAtual] + par.second < custos[par.first])
                {
                    custos[par.first] = custos[noAtual] + par.second;
                    heap.push(pair<int, int>(custos[par.first], par.first));
                }
            }
            else
            {
                custos[par.first] = custos[noAtual] + par.second;
                heap.push(pair<int, int>(custos[par.first], par.first));
            }
        }
    }

    return custos[fim];
}