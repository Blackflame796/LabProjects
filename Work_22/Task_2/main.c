#include <stdio.h>
#include <math.h>
#include <locale.h>

// Объявление типа указателя на функцию
typedef double (*TFun)(double);

// Объявление прототипов функций
double Y(double x);
double V(double x);
double tabulate_function(TFun f, double start, double end, double step);
double calculate_range(TFun f, double a, double b);

int main() {
    setlocale(LC_ALL,"RUS");
    int choice, function_choice;
    double x, a, b, h, result;
    TFun selected_function;
    
    do {
        printf("1. Вычислить значение функции\n");
        printf("2. Табулировать функцию\n");
        printf("3. Вычислить размах функции\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nВыберите функцию:\n");
                printf("1. Y(x) = 2*sin(πx)*sin(3πx) - 0.5\n");
                printf("2. V(x) - кусочная функция\n");
                printf("Ваш выбор: ");
                scanf("%d", &function_choice);
                
                printf("Введите x: ");
                scanf("%lf", &x);
                
                switch(function_choice) {
                    case 1:
                        result = Y(x);
                        printf("Y(%.2f) = %.4f\n", x, result);
                        break;
                    case 2:
                        result = V(x);
                        printf("V(%.2f) = %.4f\n", x, result);
                        break;
                    default:
                        printf("Неверный выбор!\n");
                }
                break;
                
            case 2:
                printf("\nВыберите функцию:\n");
                printf("1. Y(x) = 2*sin(πx)*sin(3πx) - 0.5\n");
                printf("2. V(x) - кусочная функция\n");
                printf("Ваш выбор: ");
                scanf("%d", &function_choice);
                
                printf("Введите начало интервала a: ");
                scanf("%lf", &a);
                printf("Введите конец интервала b: ");
                scanf("%lf", &b);
                printf("Введите шаг h: ");
                scanf("%lf", &h);
                
                switch(function_choice) {
                    case 1:
                        printf("\nТабуляция функции Y(x):\n");
                        result = tabulate_function(Y, a, b, h);
                        printf("Последнее значение функции: %.4f\n", result);
                        break;
                    case 2:
                        printf("\nТабуляция функции V(x):\n");
                        result = tabulate_function(V, a, b, h);
                        printf("Последнее значение функции: %.4f\n", result);
                        break;
                    default:
                        printf("Неверный выбор!\n");
                }
                break;
                
            case 3:
                printf("\nВыберите функцию:\n");
                printf("1. Y(x) = 2*sin(πx)*sin(3πx) - 0.5\n");
                printf("2. V(x) - кусочная функция\n");
                printf("Ваш выбор: ");
                scanf("%d", &function_choice);
                
                printf("Введите начало интервала a: ");
                scanf("%lf", &a);
                printf("Введите конец интервала b: ");
                scanf("%lf", &b);
                
                switch(function_choice) {
                    case 1:
                        printf("\nРазмах функции Y(x):\n");
                        result = calculate_range(Y, a, b);
                        printf("Размах по оси Y: %.4f\n", result);
                        break;
                    case 2:
                        printf("\nРазмах функции V(x):\n");
                        result = calculate_range(V, a, b);
                        printf("Размах по оси Y: %.4f\n", result);
                        break;
                    default:
                        printf("Неверный выбор!\n");
                }
                break;
                
            case 4:
                break;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while(choice != 4);
    
    return 0;
}

//--- Математические функции ---

// Y(x) = 2*sin(πx)*sin(3πx) - 0.5
double Y(double x) {
    return 2 * sin(M_PI * x) * sin(3 * M_PI * x) - 0.5;
}

// V(x) - кусочная функция
double V(double x) {
    if (x < 0) {
        return (1 + 2*x) / (1 + x*x);
    }
    else if (x < 1) {
        return sin(x) * sin(x) * sqrt(1 + x);
    }
    else {
        return sin(x) * sin(x) * exp(0.2 * x);
    }
}

//--- Функция табуляции ---
double tabulate_function(TFun f, double start, double end, double step) {
    printf(" x\t\t y\n");
    printf("--------------------\n");
    
    double last_value = 0;
    
    for(double x = start; x <= end; x += step) {
        double y = f(x);
        printf("%6.2f\t%10.4f\n", x, y);
        last_value = y;
    }
    
    return last_value;
}

//--- Функция вычисления размаха ---
double calculate_range(TFun f, double a, double b) {
    double min_y = f(a);
    double max_y = f(a);
    
    // Проверяем значения функции в 100 точках на интервале
    int steps = 100;
    double step = (b - a) / steps;
    
    for(int i = 0; i <= steps; i++) {
        double x = a + i * step;
        double y = f(x);
        
        if(y < min_y) min_y = y;
        if(y > max_y) max_y = y;
    }
    
    double x_range = b - a;
    double y_range = max_y - min_y;
    
    printf("Размах по оси X: %.4f\n", x_range);
    printf("Минимальное значение Y: %.4f\n", min_y);
    printf("Максимальное значение Y: %.4f\n", max_y);
    
    return y_range;
}