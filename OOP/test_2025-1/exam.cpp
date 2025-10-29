#include <iostream>
using namespace std;

class Contador{
    private:
        int valor;

    public:
        Contador() { valor = 0; }
        void Incrementar() { valor++; }
        int  ObterValor() const { return valor; }
};



int main()
{
    const int lim = 5;
    for(int i = 0; i < lim; i++){
        if(i % 2 == 0)
            std::cout << i << " ";
    }
    
    cout << "\n";


    int n = 10;
    //cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i + 10;
    }
    delete[] arr;


    int x = 10;
    int *p = &x;
    *p = 20;
    cout << x << "\n";


    Contador c;
    c.Incrementar();
    cout << c.ObterValor() << "\n";
}
