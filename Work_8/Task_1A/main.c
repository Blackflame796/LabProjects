#include <stdio.h>
#include <math.h>
#include <locale.h>

double convert_to_k(double num)
{
    double result = num / 1024.0;
    return result;
}

int main() {
    setlocale(LC_ALL, "RUS");
    // int n;
    // printf("Введите степень n: ");
    // scanf("%d", &n);

    // double value = 1;

    // for (int i = 0; i <= n; i++) {
    //     value = pow(2, i);
    //     printf(" 2^%-2d = %12.0f\n", i, value);
    // }

    // double k = convert_to_k(value);

    // printf("Результат: %.1fK\n", k);

    int m;
    printf("Введите число m: ");
    scanf("%d", &m);

    double value = 1;
    int log_m = log2(m);

    for (int i = 0; i <= log_m; i++) {
        value = pow(2, i);
        printf(" 2^%-2d = %12.0f\n", i, value);
    }

    double k = convert_to_k(value);

    printf("Результат: %.1fK\n", k);

    return 0;
}
