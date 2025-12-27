#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double* full_elements(double *ptr_array, int size);
double* calc_elements(double *ptr_array, int size);
int put_elements(double *ptr_array, int size);

int main() {
    setlocale(LC_ALL,"RUS");
    double *ptr_array;
    int size;
    
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        puts("Ошибка: неверный размер массива");
        return -1;
    }
    
    ptr_array = (double*)malloc(size * sizeof(double));
    if (!ptr_array) {
        puts("Ошибка выделения памяти");
        return -1;
    }
    
    ptr_array = full_elements(ptr_array, size);
    
    printf("\nИсходный массив:\n");
    put_elements(ptr_array, size);

    ptr_array = calc_elements(ptr_array, size);
    
    
    
    printf("\nМассив после замены нулевых элементов на их порядковый номер:\n");
    put_elements(ptr_array, size);
    
    free(ptr_array);
    
    return 0;
}

double* full_elements(double *ptr_array, int size) {
    double start = 2.0;
    double end = 4.1;
    double step = (end - start) / (size - 1);
    
    for (int i = 0; i < size; i++) {
        double x = start + i * step;
        double a = fabs(log10(x));        // |lg(x)|
        double b = pow(x - 2, 2);         // (x-2)²
        ptr_array[i] = a - b;             // f(x) = |lg(x)| - (x-2)²
    }
    return ptr_array;
}

double* calc_elements(double *ptr_array, int size) {
    
    for (int i = 0; i < size; i++) {
        if (ptr_array[i] == 0.0) {
            ptr_array[i] = (double)(i + 1);
        }
    }
    
    return ptr_array;
}

int put_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Элемент [%d] = %.4f\n", i, ptr_array[i]);
    }
    return 0;
}