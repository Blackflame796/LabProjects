// 12 вариант
#include <stdio.h>
#include <math.h>

double calculate_a(double x)
{
    double result = fabs(log10(x));
    return result;
}

double calculate_b(double x)
{
    double result = pow(x - 2, 2);
    return result;
}

int main() {
    double x, y, a, b;
    double step;

    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);

    printf("\nТаблица значений функции на интервале [2; 4.1]:\n");
    printf("-----------------------------------\n");
    printf("|    x    |       f(x)            |\n");
    printf("-----------------------------------\n");


    for (x = 2.0; x <= 4.1; x += step) {
        a = calculate_a(x);
        b = calculate_b(x);
        y = a - b;
        printf("| %7.2f | %21.6f |\n", x, y);
    }

    printf("-----------------------------------\n");
    return 0;
}
