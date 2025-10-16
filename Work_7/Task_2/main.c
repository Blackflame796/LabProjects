#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float x, y, result;
    char c;
    
    printf("=== КАЛЬКУЛЯТОР ===\n");
    printf("Доступные операции:\n");
    printf("+ - сложение\n");
    printf("- - вычитание\n");
    printf("* - умножение\n");
    printf("/ - деление\n");
    printf("Введите выражение: ");
    scanf("%f%c%f", &x, &c, &y);
    
    switch(c) {
        case '+':
            result = x + y;
            printf("%g %c %g = %f\n", x, c, y, result);
            break;
            
        case '-':
            result = x - y;
            printf("%g %c %g = %f\n", x, c, y, result);
            break;
            
        case '*':
            result = x * y;
            printf("%g %c %g = %f\n", x, c, y, result);
            break;
            
        case '/':
            if (y != 0) {
                result = x / y;
                printf("%g %c %g = %f\n", x, c, y, result);
            } else {
                printf("Ошибка: деление на ноль!\n");
            }
            break;
        
        case '^':
            result = powf(x, y);
            printf("%g %c %g = %f\n", x, c, y, result);
            break;
            
        default:
            printf("Ошибка: неизвестная операция '%c'\n", c);
            break;
    }
    
    return 0;
}