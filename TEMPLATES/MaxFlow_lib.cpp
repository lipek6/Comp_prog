/**
 * BIBLIOTECA DE GRAFOS - FLUXO MÁXIMO (DINIC)
 * * Algoritmo: Dinic
 * Complexidade: O(V^2 * E) no geral, mas O(E * sqrt(V)) para redes unitárias (Matching Bipartido).
 * Muito mais rápido que Edmonds-Karp.
 * * Conceitos Chave:
 * 1. Rede Residual: Arestas com capacidade restante.
 * 2. Level Graph (BFS): Divide os nós em níveis baseados na distância da fonte.
 * Isso garante que apenas avançamos em direção ao sorvedouro.
 * 3. Blocking Flow (DFS): Empurra o máximo de fluxo possível usando apenas arestas
 * que vão do nível L para L+1.
 * * Ideal para: CSES "Download Speed", "Police Chase", UVA "Software Allocation".
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct FlowEdge {
    int v;              // Destino
    int rev;            // Índice da aresta reversa na lista de adjacência de 'v'
    long long cap;      // Capacidade total
    long long flow;     // Fluxo atual passando pela aresta
};

struct Dinic {
    int n;
    int s, t; // Source, Sink
    vector<vector<FlowEdge>> adj;
    vector<int> level; // Nível de cada nó (distância da source na rede residual)
    vector<int> ptr;   // Ponteiro para a próxima aresta a ser explorada (otimização)

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }

    // Adiciona aresta direcionada com capacidade 'cap'
    void add_edge(int u, int v, long long cap) {
        // Aresta direta: u -> v
        FlowEdge a = {v, (int)adj[v].size(), cap, 0};
        // Aresta reversa: v -> u (capacidade 0 inicialmente)
        FlowEdge b = {u, (int)adj[u].size(), 0, 0}; 
        
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    // BFS: Constrói o Level Graph (rotula distâncias a partir de S)
    // Retorna true se T for alcançável a partir de S
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto& e : adj[u]) {
                // Se a aresta tem capacidade residual e o destino não foi visitado
                if (e.cap - e.flow > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    // DFS: Encontra "Blocking Flow" no Level Graph
    // 'pushed' é o fluxo que estamos tentando empurrar
    long long dfs(int u, long long pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed; // Chegamos no sorvedouro

        // O loop começa de ptr[u]. Isso é crucial!
        // Arestas que não levaram ao sorvedouro em chamadas anteriores são puladas.
        for (int& cid = ptr[u]; cid < adj[u].size(); ++cid) {
            auto& e = adj[u][cid];
            int v = e.v;

            // Só vamos para v se ele estiver no próximo nível e houver capacidade
            if (level[u] + 1 != level[v] || e.cap - e.flow == 0) continue;

            long long tr = dfs(v, min(pushed, e.cap - e.flow));
            if (tr == 0) continue;

            // Atualiza fluxos
            e.flow += tr;
            adj[v][e.rev].flow -= tr; // Fluxo negativo na aresta reversa

            return tr;
        }
        return 0;
    }

    long long max_flow() {
        long long flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0); // Reseta ponteiros para nova fase
            while (long long pushed = dfs(s, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};