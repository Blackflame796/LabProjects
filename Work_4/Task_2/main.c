#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int a = 11;
    int b = 3;
    
    printf("Исходные значения:\n");
    printf("a = %d, b = %d\n\n", a, b);
    
    // int x;
    // float y;
    // double z;

    // x = a / b;
    // y = a / b;
    // z = a / b;
    
    // printf("x = %d\n", x);
    // printf("y = %f\n", y);
    // printf("z = %lf\n\n", z);
    
    printf("(float)(a/b) = %f\n", (float)(a/b));
    printf("(double)(a/b) = %lf\n\n", (double)(a/b));

    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}