#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 3;
    int L = 33;

    puts("Дано:");
    printf("%10d\n%10d\n%15.7s\nОтвет: \n%+13.2f\n", n, L, "________", (double)n / L);
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}