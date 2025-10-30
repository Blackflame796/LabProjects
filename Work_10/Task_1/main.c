#include <stdio.h>
#include <math.h>
#include <locale.h>

double fa(double x) {
    double y;
    if (x <= 3) {
        y = pow(x,2) - 3 * x + 9;
    } else {
        y = 1 / (pow(x,3) + 3);
    }
    return y;
}

double fb(double x) {
    return x * exp(sin(pow(x,2)));
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    double x;
    double result;
    int choice;
    
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    do {
        printf("\nМеню:\n");
        printf("1. Вычислить F1(x)\n");
        printf("2. Вычислить F2(x)\n");
        printf("3. Вычислить произведение функций\n");
        printf("4. Вычислить разность квадратов функций\n");
        printf("5. Вычислить удвоенную сумму функций\n");
        printf("6. Выход\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                result = fa(x);
                printf("F1(x) = %lf\n", result);
                break;
            case 2:
                result = fb(x);
                printf("F2(x) = %lf\n", result);
                break;
            case 3:
                result = fa(x) * fb(x);
                printf("Произведение: %lf\n", result);
                break;
            case 4:
                result = fa(x) * fa(x) - fb(x) * fb(x);
                printf("Разность квадратов: %lf\n", result);
                break;
            case 5:
                result = 2 * (fa(x) + fb(x));
                printf("Удвоенная сумма: %lf\n", result);
                break;
            case 6:
                break;
            default:
                printf("Выбран неверный номер пункта меню!\n");
        }
    } while(choice != 6);
    
    return 0;
}