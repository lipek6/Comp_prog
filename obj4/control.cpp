#include<iostream>

int main (void)
{
    // Arrays: Linear sequences, statics, and homogenous
    int arr[5] = {10, 20, 30, 40, 50};
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 
    printf("Writing a simple array:\n");
    
    for (int num : arr)
    {
        printf("%i, ", num);
    }

    printf("\nWriting a simple matrix:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            printf("%i", matrix[i][j]);
        }
        printf("\n");


        printf("Give me the array size");
        int size;
        scanf("%i", &size);
        printf("\n");

        int u_arr[size];




    }

}