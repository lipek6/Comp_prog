#include<bits/stdc++.h>
using namespace std;

// Vamos limitar o vetor a 93 (índices 0 a 92),
// pois n > 92 estoura a capacidade de um long long int.
vector<long long int> fibs(93, -1);
int last_idx = 2; // Começamos em 2, pois 0 e 1 já estão preenchidos

// n pode ser um int, já que é apenas um índice.
long long int fib (int n)
{
    // 1. Proteção contra overflow/índice inválido
    if (n >= 93) {
        // Se n for muito grande, apenas calculamos o máximo possível
        n = 92;
    }

    // 2. [BUG CORRIGIDO] Retorna o valor se já foi calculado
    // Retornamos fibs[n], e não fibs[n-1]
    // Isso também corrige o bug de n=0 e n=1.
    if(fibs[n] != -1) {
        return fibs[n];
    }

    // 3. Calcula os valores que faltam
    // Começa de onde paramos (last_idx) e vai até n.
    for(int i = last_idx; i <= n; i++)
    {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }

    // 4. [LÓGICA CORRIGIDA] Atualiza o índice para a próxima chamada
    // Já calculamos tudo até 'n', então o próximo cálculo
    // pode começar em 'n + 1'.
    last_idx = n + 1;
    
    // 5. Retorna o valor calculado
    return fibs[n];
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Preenche os casos base
    fibs[0] = 0;
    fibs[1] = 1;
    
    int n; // n não precisa ser long long

    // Exemplo de chamadas:
    // Se você digitar: 5, 10, 7, 12

    cin >> n; // Digamos, n = 5
    cout << fib(n) << endl; // Calcula fib(2) a fib(5). last_idx vira 6.

    cin >> n; // Digamos, n = 10
    cout << fib(n) << endl; // Calcula fib(6) a fib(10). last_idx vira 11.

    cin >> n; // Digamos, n = 7
    cout << fib(n) << endl; // fibs[7] != -1. Retorna fibs[7] imediatamente.

    cin >> n; // Digamos, n = 12
    cout << fib(n) << endl; // Calcula fib(11) e fib(12). last_idx vira 13.
}