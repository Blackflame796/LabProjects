#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функция для вычисления факториала
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Вычисление ctg(x) с помощью стандартной библиотеки
double ctg_standard(double x) {
    return 1.0 / tan(x);
}

// Получение числа Бернулли по индексу через switch
double get_bernoulli(int n) {
    switch (n) {
        case 1: return 1.0/6.0;           // B2
        case 2: return -1.0/30.0;         // B4  
        case 3: return 1.0/42.0;          // B6
        case 4: return -1.0/30.0;         // B8
        case 5: return 5.0/66.0;          // B10
        case 6: return -691.0/2730.0;     // B12
        case 7: return 7.0/6.0;           // B14
        case 8: return -3617.0/510.0;     // B16
        case 9: return 43867.0/798.0;     // B18
        case 10: return -174611.0/330.0;  // B20
        case 11: return 854513.0/138.0;   // B22
        case 12: return -236364091.0/2730.0; // B24
        case 13: return 8553103.0/6.0;    // B26
        case 14: return -23749461029.0/870.0; // B28
        case 15: return 8615841276005.0/14322.0; // B30
        default: return 0.0;
    }
}

double ctg_n(double x, int N) {
    // Приводим x к диапазону (-π, π)
    while (x > M_PI) x -= 2 * M_PI;
    while (x < -M_PI) x += 2 * M_PI;
    
    // Особенность в точке x=0
    if (fabs(x) < 0.0000000001) {
        return 1.0 / x;
    }
    
    double result = 1.0 / x;  // Первый член ряда
    double x_power = x;       // Текущая степень x
    
    for (int i = 1; i <= N; i++) {
        if (i > 15) break;  // Используем только первые 15 чисел Бернулли
        
        double bernoulli = get_bernoulli(i);
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        double power_of_2 = pow(2.0, 2*i);
        double fact = factorial(2*i);
        
        double coefficient = sign * power_of_2 * bernoulli / fact;
        double term = coefficient * x_power;
        
        result += term;
        x_power = x_power * x * x;
    }
    
    return result;
}

double ctg_eps(double x, double eps) {
    while (x > M_PI) x -= 2 * M_PI;
    while (x < -M_PI) x += 2 * M_PI;
    
    if (fabs(x) < 0.0000000001) {
        return 1.0 / x;
    }
    
    double result = 1.0 / x;
    double x_power = x;
    int i = 1;
    double term;
    
    do {
        if (i > 15) break;
        
        double bernoulli = get_bernoulli(i);
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        double power_of_2 = pow(2.0, 2*i);
        double fact = factorial(2*i);
        
        double coefficient = sign * power_of_2 * bernoulli / fact;
        term = coefficient * x_power;
        
        result += term;
        x_power = x_power * x * x;
        i++;
        
    } while (fabs(term) > eps && i <= 100);
    
    return result;
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    double x, eps;
    int N;
    
    printf("Введите x: ");
    scanf("%lf", &x);
    
    printf("Введите количество членов ряда N (максимум 15): ");
    scanf("%d", &N);
    
    printf("Введите точность eps: ");
    scanf("%lf", &eps);
    
    double standard_result = ctg_standard(x);
    
    printf("┌──────────────────┬────────────────────┬────────────┐\n");
    printf("│     Метод        │      Результат     │ Отклонение │\n");
    printf("├──────────────────┼────────────────────┼────────────┤\n");
    
    // Стандартная функция
    printf("│ Стандартная      │%18.6f  │ %10.6f │\n", 
           standard_result, 0.0);
    
    double result_n = ctg_n(x, N);
    double deviation_n = fabs(standard_result - result_n);
    printf("│ Ряд (N=%d)       │%18.6f  │ %10.6f │\n", 
           N, result_n, deviation_n);
    
    double result_eps = ctg_eps(x, eps);
    double deviation_eps = fabs(standard_result - result_eps);
    printf("│ Ряд (точность)   │%18.6f  │ %10.6f │\n", 
           result_eps, deviation_eps);
    
    printf("└──────────────────┴────────────────────┴────────────┘\n");
    
    printf("\nВлияние количества членов ряда на точность:\n");
    printf("┌─────┬────────────────────┬────────────┐\n");
    printf("│  N  │       ctg(x)       │ Отклонение │\n");
    printf("├─────┼────────────────────┼────────────┤\n");
    
    int max_display = (N > 15) ? 15 : N;
    for (int n = 1; n <= max_display; n++) {
        double result = ctg_n(x, n);
        double deviation = fabs(standard_result - result);
        printf("│ %3d │ %18.6f │ %10.6f │\n", n, result, deviation);
    }
    printf("└─────┴────────────────────┴────────────┘\n");
    
    
    return 0;
}