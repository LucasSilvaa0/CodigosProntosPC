#include <bits/stdc++.h>
using namespace std;
#define ll long long

class EdmondsKarp {
public:
    int V;  // Número de vértices
    vector<vector<int>> capacity;  // Matriz de capacidades
    vector<vector<int>> flow;  // Matriz de fluxos

    // Construtor
    EdmondsKarp(int V) {
        this->V = V;
        capacity.assign(V, vector<int>(V, 0));  // Inicializa com capacidade 0
        flow.assign(V, vector<int>(V, 0));  // Inicializa com fluxo 0
    }

    // Método para adicionar uma aresta com capacidade
    void addEdge(int u, int v, int cap) {
        capacity[u][v] += cap;  // A capacidade pode ser aumentada se já houver uma aresta
    }

    // Método para encontrar o caminho aumentante usando BFS
    bool bfs(int source, int sink, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;

        // Inicia com a fonte
        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Itera sobre todos os vértices adjacentes
            for (int v = 0; v < V; v++) {
                // Se o vértice v não foi visitado e há capacidade residual (capacidade - fluxo)
                if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                    parent[v] = u;  // Registra o vértice anterior para o caminho
                    if (v == sink) return true;  // Se chegou ao sumidouro, encontramos o caminho
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;  // Não encontrou um caminho aumentante
    }

    // Algoritmo de Edmonds-Karp para encontrar o fluxo máximo
    int edmondsKarp(int source, int sink) {
        int maxFlow = 0;
        vector<int> parent(V);

        // Enquanto houver um caminho aumentante
        while (bfs(source, sink, parent)) {
            // Encontra o valor do fluxo mínimo (bottleneck) no caminho encontrado
            int pathFlow = INT_MAX;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
            }

            // Atualiza os fluxos das arestas ao longo do caminho
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                flow[u][v] += pathFlow;
                flow[v][u] -= pathFlow;  // Fluxo reverso
            }

            maxFlow += pathFlow;  // Incrementa o fluxo máximo
        }

        return maxFlow;
    }
};