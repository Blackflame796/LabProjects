#include <stdio.h>

int main() {
    int N, K;

    printf("Введите текущее время (часы минуты): ");
    scanf("%d %d", &N, &K);

    printf("Сейчас %d часов %d минут 00 секунд\n", N, K);

    printf("Идет %d минута суток\n", N * 60 + K);

    printf("До полуночи осталось %d часов и %d минут\n", 23 - N, 60 - K);

    int seconds_since_eight_am = (N - 8) * 3600 + K * 60;
    printf("С 8.00 прошло %d секунд\n", seconds_since_eight_am);

    printf("Текущий час = %d/24 суток и текущая минута = %d/60 часа\n", N, K);

    return 0;
}