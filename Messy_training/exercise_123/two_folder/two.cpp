#include<iostream>
#include<tgmath.h>

int main(void)
{
    double pi = 2 * acos(0.0);
    int n;
    scanf("%d", &n);
    printf("%.*lf\n", n, pi); // this is the way to manipulate field width
}