#include<iostream>


int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cout << "Digite o tamanho do array" << std::endl;
    std::cin >> n;

    int *arr = new int[n];  // "new" reserves memory on the heap
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = 10 * i;
    }    

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    delete[] arr;

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

}