#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

double* full_elements(double *ptr_array, int size);
double* insert(double* ptr_arr, int *size, int index, double num);
int put_elements(double *ptr_array, double *original_array, int size, int original_size);

int main() {
    setlocale(LC_ALL,"RUS");
    double *ptr_array, *original_array;
    int size, original_size;
    
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        puts("Ошибка: неверный размер массива");
        return -1;
    }
    
    original_size = size;
    
    ptr_array = (double*)malloc(size * sizeof(double));
    original_array = (double*)malloc(size * sizeof(double));
    if (!ptr_array || !original_array) {
        puts("Ошибка выделения памяти");
        free(ptr_array);
        free(original_array);
        return -1;
    }
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    ptr_array = full_elements(ptr_array, size);
    
    for (int i = 0; i < size; i++) {
        original_array[i] = ptr_array[i];
    }

    int negative_index = -1;
    for (int i = 0; i < size; i++) {
        if (ptr_array[i] < 0) {
            negative_index = i;
            break;
        }
    }
    
    if (negative_index != -1) {
        ptr_array = insert(ptr_array, &size, negative_index, -999.0);
    } else {
        printf("Отрицательные элементы не найдены. Вставка не выполнена.\n");
    }
    
    printf("\nМассив после вставки -999 перед первым отрицательным элементом:\n");
    if (size > 0) {
        put_elements(ptr_array, original_array, size, original_size);
        printf("Новый размер массива: %d\n", size);
    } else {
        printf("Массив пуст\n");
    }
    
    free(ptr_array);
    free(original_array);
    
    return 0;
}

double* full_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }
    return ptr_array;
}

double* insert(double* ptr_arr, int *size, int index, double num) {
    /*
    ptr_arr - адрес массива
    size - число элементов
    index - индекс добавляемого элемента
    num - вставляемое значение
    */
    int size_n = (*size) + 1;
    if (ptr_arr == NULL) return NULL;
    
    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
    if (ptr_arr_n == NULL) return ptr_arr;
    
    ptr_arr = ptr_arr_n;
    
    // Сдвиг элементов вправо, начиная с позиции вставки
    for (int i = size_n - 1; i > index; i--) {
        ptr_arr[i] = ptr_arr[i - 1];
    }
    
    ptr_arr[index] = num;
    *size = size_n;
    return ptr_arr;
}

int put_elements(double *ptr_array, double *original_array, int size, int original_size) {
    printf("┌─────────┬──────────────────┬──────────────────┐\n");
    printf("│ Индекс  │ Исходное значение│  Новое значение  │\n");
    printf("├─────────┼──────────────────┼──────────────────┤\n");
    
    for (int i = 0; i < original_size; i++) {
        if (i < size) {
            printf("│ %7d │ %16.4f │ %16.4f │\n", i, original_array[i], ptr_array[i]);
        } else {
            printf("│ %7d │ %16.4f │ %16s │\n", i, original_array[i], "-");
        }
    }
    if (size > original_size) {
        for (int i = original_size; i < size; i++) {
            printf("│ %7d │ %16s │ %16.4f │\n", i, "-", ptr_array[i]);
        }
    }
    
    printf("└─────────┴──────────────────┴──────────────────┘\n");
    return 0;
}