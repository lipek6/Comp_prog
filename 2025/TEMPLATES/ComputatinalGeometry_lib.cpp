/**
 * BIBLIOTECA DE GEOMETRIA COMPUTACIONAL (2D)
 * * Lógica Base: Evitar floats/doubles sempre que possível para não ter erros de precisão.
 * Usamos Produto Vetorial (Cross Product) para quase tudo (área, orientação, intersecção).
 * * Conteúdo:
 * 1. Struct Point e Operadores
 * 2. Cross Product (Orientação)
 * 3. Área de Polígono (Shoelace)
 * 4. Convex Hull (Monotone Chain)
 * 5. Ponto dentro de Polígono
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Usar long long para coordenadas inteiras previne overflow no produto vetorial
struct Point {
    long long x, y;

    // Operadores para facilitar sintaxe vetorial
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
};

// ==================================================================================
// 1. PRODUTO VETORIAL (CROSS PRODUCT)
// CP = x1*y2 - x2*y1
// Interpretação geométrica fundamental:
// > 0: Ponto 'b' está à ESQUERDA do vetor 'a' (sentido anti-horário)
// < 0: Ponto 'b' está à DIREITA do vetor 'a' (sentido horário)
// = 0: Vetores colineares
// ==================================================================================
long long cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Retorna orientação de 3 pontos ordenados (p, q, r)
// O vetor base é pq (q - p), testamos r em relação a ele.
long long orientation(Point p, Point q, Point r) {
    return cross_product(q - p, r - q);
}

// ==================================================================================
// 2. CONVEX HULL (MONOTONE CHAIN)
// Encontra o menor polígono convexo que engloba todos os pontos.
// Complexidade: O(N log N) devido à ordenação.
// Ideal para: CSES "Convex Hull", UVA "Board Wrapping".
// ==================================================================================
vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    if (n <= 2) return points;

    sort(points.begin(), points.end());

    vector<Point> hull;

    // Construção da casca inferior (Lower Hull)
    for (int i = 0; i < n; ++i) {
        // Enquanto houver pelo menos 2 pontos na pilha e o novo ponto criar
        // uma curva no sentido horário (ou colinear), removemos o último ponto.
        // Queremos apenas curvas anti-horárias (convexidade).
        while (hull.size() >= 2 && orientation(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Construção da casca superior (Upper Hull)
    int lower_hull_size = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_hull_size && orientation(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove o duplicado (primeiro e último são iguais)
    return hull;
}

// ==================================================================================
// 3. ÁREA DE POLÍGONO (SHOELACE FORMULA)
// Área = 0.5 * |sum(x_i * y_{i+1} - x_{i+1} * y_i)|
// Ideal para: UVA "Area".
// ==================================================================================
double polygon_area(const vector<Point>& points) {
    double area = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        area += cross_product(points[i], points[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

// ==================================================================================
// 4. PONTO EM POLÍGONO (RAY CASTING)
// Verifica se um ponto P está dentro de um polígono (não precisa ser convexo).
// Lógica: Traça um raio horizontal. Se cruzar as arestas um nº ímpar de vezes -> dentro.
// Retorna: 0 (fora), 1 (dentro), 2 (na borda)
// Ideal para: CSES "Point in Polygon".
// ==================================================================================
int point_in_polygon(Point p, const vector<Point>& polygon) {
    bool inside = false;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        // Verifica se está na borda (segmento ab)
        if (orientation(a, b, p) == 0 && 
            min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
            min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) return 2;

        // Algoritmo Ray Casting
        // Verifica se o raio horizontal partindo de P cruza o segmento AB
        if (((a.y > p.y) != (b.y > p.y)) && // Um ponto acima, outro abaixo de P
            (p.x < (b.x - a.x) * (p.y - a.y) / (double)(b.y - a.y) + a.x)) {
            inside = !inside;
        }
    }
    return inside ? 1 : 0;
}