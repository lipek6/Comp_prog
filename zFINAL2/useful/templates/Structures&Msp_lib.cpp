/**
 * BIBLIOTECA DE GRAFOS - ESTRUTURAS E ÁRVORES GERADORAS
 * * Conteúdo:
 * 1. DSU (Disjoint Set Union) - Fundamental para Kruskal e componentes conexas.
 * 2. Kruskal (Minimum Spanning Tree) - O(E log E)
 * 3. Topological Sort (Kahn's Algorithm) - O(V + E)
 * 4. Bipartite Check (DFS Color)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// ==================================================================================
// 1. DISJOINT SET UNION (DSU)
// Estrutura para gerenciar conjuntos disjuntos de forma eficiente.
// Suporta duas operações principais quase O(1): unir conjuntos e encontrar representante.
// ==================================================================================
struct DSU {
    vector<int> parent;
    vector<int> size; // Usado para 'Union by Size' (balanceamento)

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        size.assign(n + 1, 1);
    }

    // Encontra o representante do conjunto com Compressão de Caminho
    // Recursivamente faz todos os nós no caminho apontarem direto para a raiz.
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    // Une dois conjuntos
    // Retorna true se a união aconteceu (eles eram desconexos), false caso contrário.
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            // Liga a árvore menor na maior para manter a altura pequena
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

// Estrutura de aresta para Kruskal (precisa conectar u e v com peso w)
struct Edge {
    int u, v;
    long long weight;
    // Operador < para ordenação
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// ==================================================================================
// 2. ALGORITMO DE KRUSKAL (MST)
// Lógica: Guloso. Ordena todas as arestas por peso crescente e adiciona a aresta
// à árvore se ela não formar um ciclo (verificado pelo DSU).
// Ideal para: CSES "Road Reparation", "Re-connecting Computer Sites".
// ==================================================================================
long long kruskal(int n, vector<Edge>& edges) {
    long long mst_cost = 0;
    int edges_count = 0;
    DSU dsu(n);

    sort(edges.begin(), edges.end()); // Passo crucial: ordenar pelo peso

    for (const auto& e : edges) {
        // Se u e v já estão no mesmo componente, adicionar essa aresta criaria um ciclo.
        if (dsu.unite(e.u, e.v)) {
            mst_cost += e.weight;
            edges_count++;
        }
    }

    // Se não conseguimos conectar n-1 arestas, o grafo é desconexo
    if (edges_count < n - 1) return -1;
    return mst_cost;
}

// ==================================================================================
// 3. TOPOLOGICAL SORT (Kahn's Algorithm)
// Lógica: Usa o grau de entrada (in-degree). Nós com grau 0 podem ser processados.
// Ideal para: Dependências de tarefas, CSES "Course Schedule".
// ==================================================================================
vector<int> topological_sort(int n, const vector<vector<int>>& adj) {
    vector<int> in_degree(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) in_degree[v]++;
    }

    vector<int> result;
    vector<int> q; // Pode ser uma queue normal, vector usado como pilha funciona também
    
    // Adiciona todos os nós com grau 0 inicial
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) q.push_back(i);
    }

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        result.push_back(u);

        for(int v : adj[u]){
            in_degree[v]--;
            if(in_degree[v] == 0){
                q.push_back(v);
            }
        }
    }

    if (result.size() != n) return {}; // Grafo tem ciclo!
    return result;
}

// ==================================================================================
// 4. BIPARTITE CHECK
// Lógica: Tenta colorir o grafo com 2 cores. Se um vizinho tiver a mesma cor, falha.
// Ideal para: CSES "Building Teams".
// ==================================================================================
bool is_bipartite(int n, const vector<vector<int>>& adj, vector<int>& color) {
    color.assign(n + 1, 0); // 0: sem cor, 1: cor A, 2: cor B
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            vector<int> q = {i};
            color[i] = 1;
            int head = 0;
            
            while(head < q.size()){
                int u = q[head++];
                for(int v : adj[u]){
                    if(color[v] == 0){
                        color[v] = (color[u] == 1 ? 2 : 1); // Alterna cor
                        q.push_back(v);
                    } else if (color[v] == color[u]){
                        return false; // Conflito de cores
                    }
                }
            }
        }
    }
    return true;
}