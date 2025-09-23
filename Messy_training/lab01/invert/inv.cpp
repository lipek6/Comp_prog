#include <iostream>

int main (void)
{
    srand(time(0));
    int size;

    printf("Digite o tamanho do array ");
    scanf("%i\n", &size);
    
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
        printf("%i\n", array[i]);
    }



    int i = 0;
    int aux;
    for (int j = size; j < size - 1; j--)
    {
        aux      = array[j];
        array[j] = array[i];
        array[i] = aux;
        i++;
        printf("%i\n", array[i]);
    }
    

}