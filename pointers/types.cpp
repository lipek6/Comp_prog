#include<iostream>

int main (void)
{
    // Signed integer variables
    short     v_short;              // 2 Bytes
    int       v_int;                // 4 Bytes
    long      v_long;               // 4 or 8 Bytes
    long long v_llong;              // 8 Bytes

    // Unsigned integer variables
    unsigned short     v_ushort;    // 2 Bytes
    unsigned int       v_uint;      // 4 Bytes
    unsigned long      v_ulong;     // 4 or 8 Bytes
    unsigned long long v_ullong;    // 8 Bytes

    // Floating point variables
    float  v_float;                 // 4 Bytes
    double v_double;                // 8 Bytes

    // Assigning values to the variables
    v_short   = 1;
    v_int     = 2;  
    v_long    = 3; 
    v_llong   = 4;
    
    v_ushort  = 5;
    v_uint    = 6;
    v_ulong   = 7;
    v_ullong  = 8;




    int* p_int = &v_int;    // Pointer to a integer
    int** pp_int = &p_int;


    printf("O valor do inteiro é %d\n", v_int);
    printf("O tamanho do inteiro é %ld bytes\n", sizeof(v_int));
    printf("A localização do inteiro é %p\n", &v_int);

    printf("O ponteiro para este inteiro aponta para o endereço %p\n", p_int);
    printf("O tamanho do ponteiro é %ld bytes\n", sizeof(p_int));
    printf("A localização do ponteiro é %p\n", &p_int);
    printf("O que há dentro do endereço que este ponteiro está apontando é %i\n", *p_int);
    printf("O ponteiro para este ponteiro aponta para o endereço %p\n", pp_int);
    printf("O que há dentro do endereço que este ponteiro de um ponteiro está apontando é %p\n", *pp_int);
    printf("O que há dentro do endereço do endereço que este ponteiro de um ponteiro está apontando é %i\n", **pp_int);

}

