#include <stdio.h>
#include <math.h>
#include <locale.h>

#define _USE_MATH_DEFINES
#define M_PI  3.14159265358979323846

double convert(double n) {
    return n * M_PI / 180;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double gr = 0.0;
    
    printf("Введите значение в градусах: ");
    scanf("%lf", &gr);
    
    double result = convert(gr);
    printf("Sin %lf = %.6f\n", gr, sin(result));
    
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}