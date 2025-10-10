#include <locale.h>
#include <stdio.h>

void main()
{
    setlocale(LC_ALL, "RUS");
    puts ("Моя программа");
    getchar();
}