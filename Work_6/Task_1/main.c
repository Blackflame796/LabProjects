#include <stdio.h>
#include <locale.h>

int is_leap_year(int year)
{
    int result = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    return result;
}

int main()
{
    int yeas;
    printf("Введите год:");
    scanf("%d", &yeas);
    int result = is_leap_year(yeas);
    if (result == 1)
    {
        printf("Год %d високосный\n", yeas);
    }
    else
    {
        printf("Год %d не високосный\n", yeas);
    }
    return 0;
}