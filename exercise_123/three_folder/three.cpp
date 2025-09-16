#include<iostream>
#include<cstdlib>

int main (void)
{
    int day;
    char* month;
    int year;
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    month = (char*) malloc (20 * sizeof(char));

    scanf("%i %s %i", &day, month, &year);

    printf("%i %s %i\n", day, month, year);

}