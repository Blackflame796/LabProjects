#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int N = 15;
    int K = 35;
    
    printf("Сейчас %d часа(ов) %d минут 00 секунд\n", N, K);

    printf("Идет %d минута суток\n", N * 60 + K);

    printf("До полуночи осталось %d часов и %d минут\n", 23 - N, 60 - K);

    int seconds_am = (N - 8) * 3600 + K * 60;
    printf("С 8.00 прошло %d секунд\n", seconds_am);

    printf("Текущий час = %d/24 суток и текущая минута = %d/60 часа\n", N, K);
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}