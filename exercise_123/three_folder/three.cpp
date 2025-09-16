#include<iostream>

int main (void)
{
    int day;
    char* month;
    int year;
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    scanf("%i %s %i", &day, month, &year);

    printf("%i %s %i", day, month, year);

}