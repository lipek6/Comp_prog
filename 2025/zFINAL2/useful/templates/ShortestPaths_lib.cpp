/**
 * BIBLIOTECA DE GRAFOS - CAMINHO MÍNIMO
 * * Algoritmos incluídos:
 * 1. Dijkstra (Caminho único, pesos não-negativos) - O(E log V)
 * 2. Bellman-Ford (Caminho único, permite pesos negativos e detecta ciclos negativos) - O(V * E)
 * 3. Floyd-Warshall (Todos para todos) - O(V^3)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

const long long INF = numeric_limits<long long>::max();

// Estrutura simples para aresta
struct Edge {
    int to;
    long long weight;
};

// ==================================================================================
// 1. DIJKSTRA
// Lógica: Algoritmo guloso. Sempre expande o nó mais próximo da origem que ainda
// não foi processado. Usa uma Priority Queue para obter o mínimo eficientemente.
// Ideal para: CSES "Shortest Routes I", UVA "Sending email".
// ==================================================================================
vector<long long> dijkstra(int start, int n, const vector<vector<Edge>>& adj) {
    // dist[i] guarda a menor distância encontrada de 'start' até 'i'
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;

    // Min-Heap: armazena pares {distância, vértice}, ordenados pela distância menor.
    // Usamos 'greater' para inverter a ordem padrão (que é max-heap).
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Otimização "Lazy Deletion":
        // Como não podemos remover elementos do meio da priority_queue, podem haver
        // pares antigos {dist_antiga, u} na fila quando já encontramos um caminho melhor.
        // Se a distância que tiramos da fila for maior que a que já conhecemos, ignoramos.
        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long weight = edge.weight;

            // Relaxamento: Se passar por 'u' for mais rápido para chegar em 'v'
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ==================================================================================
// 2. BELLMAN-FORD
// Lógica: Relaxa todas as arestas V-1 vezes. Se, após V-1 iterações, ainda for
// possível relaxar alguma aresta, então existe um ciclo negativo.
// Ideal para: CSES "Flight Discount" (com adaptações) ou "High Score" (ciclo positivo).
// ==================================================================================
// Retorna um par: {vetor de distâncias, booleano indicando se há ciclo negativo}
pair<vector<long long>, bool> bellman_ford(int start, int n, const vector<tuple<int, int, long long>>& edges) {
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;

    // Relaxa todas as arestas n-1 vezes
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Verifica ciclo negativo (se conseguirmos relaxar mais uma vez)
    bool has_negative_cycle = false;
    for (const auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            has_negative_cycle = true;
            // Para alguns problemas, queremos propagar -INF aqui
        }
    }

    return {dist, has_negative_cycle};
}

// ==================================================================================
// 3. FLOYD-WARSHALL
// Lógica: Programação Dinâmica. Tenta melhorar o caminho entre i e j usando um
// vértice intermediário k. dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]).
// Ideal para: CSES "Shortest Routes II", N pequeno (< 500).
// ==================================================================================
void floyd_warshall(int n, vector<vector<long long>>& adj_matrix) {
    // k deve ser o laço mais externo! Representa o vértice intermediário permitido.
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj_matrix[i][k] != INF && adj_matrix[k][j] != INF) {
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                }
            }
        }
    }
}