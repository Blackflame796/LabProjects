#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 1000

// Прототипы функций
double* full_elements(double *ptr_array, int n);
int put_elements(double *ptr_array, int n);
double* calc_elements(double *ptr_array, int n);

int main() {
    setlocale(LC_ALL, "RUS");
    
    double array[N];
    int size;
    
    printf("Введите размер массива > ");
    scanf("%d", &size);
    
    if (size <= 0 || size > N) {
        printf("Ошибка: размер массива должен быть от 1 до %d\n", N);
        return 1;
    }
    
    printf("\nЗаполнение массива:\n");
    full_elements(array, size);
    
    printf("\nИсходный массив:\n");
    put_elements(array, size);
    
    printf("\nОбработка массива:\n");
    calc_elements(array, size);
    
    return 0;
}

double* full_elements(double *ptr_array, int n) {
    double start = 2.0;
    double end = 4.1;
    double step = (end - start) / (n - 1);
    
    for (int i = 0; i < n; i++) {
        double x = start + i * step;
        double a = fabs(log10(x));        // |lg(x)|
        double b = pow(x - 2, 2);         // (x-2)²
        ptr_array[i] = a - b;             // f(x) = |lg(x)| - (x-2)²
    }
    return ptr_array;
}

int put_elements(double *ptr_array, int n) {
    printf("\n┌─────────┬──────────────────┬──────────────────┐\n");
    printf("│ индекс  │ исходное значение│ новое значение   │\n");
    printf("├─────────┼──────────────────┼──────────────────┤\n");
    
    for (int i = 0; i < n; i++) {
        printf("│ %7d │ %16.6f │ %16.6f │\n", i + 1, ptr_array[i], ptr_array[i]);
    }
    
    printf("└─────────┴──────────────────┴──────────────────┘\n");
    return 0;
}

double* calc_elements(double *ptr_array, int n) {
    double original[N];
    for (int i = 0; i < n; i++) {
        original[i] = ptr_array[i];
    }
    
    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == 0.0) {
            ptr_array[i] = i + 1;
            zero_count++;
        }
    }
    
    printf("\nКоличество замененных нулевых элементов: %d\n", zero_count);
    
    printf("\n┌─────────┬──────────────────┬──────────────────┐\n");
    printf("│ индекс  │ исходное значение│ новое значение   │\n");
    printf("├─────────┼──────────────────┼──────────────────┤\n");
    
    for (int i = 0; i < n; i++) {
        printf("│ %7d │ %16.6f │ %16.6f │\n", i + 1, original[i], ptr_array[i]);
    }
    
    printf("└─────────┴──────────────────┴──────────────────┘\n");
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ptr_array[i];
    }
    printf("\nСреднее арифметическое элементов массива: %.6f\n", sum / n);
    
    return ptr_array;
}