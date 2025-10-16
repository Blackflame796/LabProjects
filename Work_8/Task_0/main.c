#include <stdio.h>
#include <locale.h>

int main() 
{
    char c_1;
    char c_2;
    int n;
    printf("Введите первый символ:");
    scanf(" %c",&c_1);
    printf("Введите второй символ:");
    scanf(" %c",&c_2);
    printf("Введите количество печатаемых символов:");
    scanf(" %d",&n);
    printf("+");
    for (int start=1; start<=n; start++) 
    {
        if (start > n / 2) {
            printf("%c!",c_1);
        }
        else {
            printf("%c!",c_2);
        }
    }
    printf("+\n");
    return 0;
}