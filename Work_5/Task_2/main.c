#include <stdio.h>
#include <math.h>
#include <locale.h>

int condition_a(int A, int B)
{
    int is_A_even = (A % 2 == 0);
    int is_B_even = (B % 2 == 0);
    int result = (is_A_even + is_B_even) == 1;
    return result;
}

int condition_b(int A, int B, int C)
{
    int is_A_mult3 = (A % 3 == 0);
    int is_B_mult3 = (B % 3 == 0);
    int is_C_mult3 = (C % 3 == 0);
    int result = (is_A_mult3 + is_B_mult3 + is_C_mult3) == 3;
    return result;
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    double t = 3.0;
    double y_const = 13.19;
    
    double x;

    // Задание 2
    printf("Введите значение x: ");
    scanf("%lf", &x);
    double a = 1.0/t + pow(x, 3);
    double b = pow(t, 2) * sqrt(fabs(a + x));
    double y = pow(log(fabs(b + pow(a, 2))), 5);

    printf("Входные параметры:\n");
    printf("\tx = %.4f\n", x);
    printf("\tt = %.1f\n", t);
    printf("\ty_const = %.2f\n", y_const);
    printf("\nРешение:\n");
    printf("\ta = 1/t + x^3 = 1/%.1f + (%.4f)^3 = %.6f\n", t, x, a);
    printf("\tb = t^2 * √|a + x| = (%.1f)^2 * √|%.6f + %.4f| = %.6f\n", t, a, x, b);
    printf("\tb + a^2 = %.6f + (%.6f)^2 = %.6f\n", b, a, b + pow(a, 2));
    printf("\tln|b + a^2| = ln|%.6f| = %.6f\n", b + pow(a, 2), log(fabs(b + pow(a, 2))));
    printf("\ty = (ln|b + a^2|)^5 = (%.6f)^5 = %.6f\n", log(fabs(b + pow(a, 2))), y);

    // Задание 3
    int A = (int)a;
    int B = (int)b; 
    int C = (int)y;
    
    int result_condition_a = condition_a(A, B);
    
    int result_condition_b = condition_b(A, B, C);
    
    printf("\nУсловия:\n");
    printf("а) Только одно из чисел А и В четное:\n");
    printf("\tУсловие выполнено (1 - да, 0 - нет): %d\n", result_condition_a);
    
    printf("б) Каждое из чисел А,В,С кратно трем:\n");
    printf("\tУсловие выполнено (1 - да, 0 - нет): %d\n", result_condition_b);
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}