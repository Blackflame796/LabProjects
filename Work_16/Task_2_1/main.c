#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

double* full_elements(double *ptr_array, int size);
int delete_k(double* ptr_arr, int* size, int** deleted_indices, int* deleted_count);
int put_elements(double *ptr_array, double *original_array, int original_size, int* deleted_indices, int deleted_count);

int main() {
    setlocale(LC_ALL,"RUS");
    double *ptr_array, *original_array;
    int *deleted_indices;
    int size, original_size, deleted_count = 0;
    
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

    int new_size = delete_k(ptr_array, &size, &deleted_indices, &deleted_count);
    
    printf("\nМассив после удаления элементов меньших среднего арифметического:\n");
    if (new_size > 0) {
        put_elements(ptr_array, original_array, original_size, deleted_indices, deleted_count);
        printf("Новый размер массива: %d\n", new_size);
    } else {
        printf("Все элементы были удалены\n");
    }
    
    free(ptr_array);
    free(original_array);
    free(deleted_indices);
    
    return 0;
}

double* full_elements(double *ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }
    return ptr_array;
}

int delete_k(double* ptr_arr, int* size, int** deleted_indices, int* deleted_count) {
    if (*size == 0) return 0;
    
    double sum = 0.0;
    for (int i = 0; i < *size; i++) {
        sum += ptr_arr[i];
    }
    double average = sum / (*size);
    
    printf("Среднее арифметическое: %.4f\n", average);
    
    *deleted_indices = (int*)malloc(*size * sizeof(int));
    *deleted_count = 0;
    
    int new_size = 0;
    for (int i = 0; i < *size; i++) {
        if (ptr_arr[i] >= average) {
            ptr_arr[new_size] = ptr_arr[i];
            new_size++;
        } else {
            // Сохраняем индекс удаленного элемента
            (*deleted_indices)[*deleted_count] = i;
            (*deleted_count)++;
        }
    }
    
    *size = new_size;
    return new_size;
}

int put_elements(double *ptr_array, double *original_array,int original_size, int* deleted_indices, int deleted_count) {
    printf("┌─────────┬──────────────────┬──────────────────┐\n");
    printf("│ Индекс  │ Исходное значение│  Новое значение  │\n");
    printf("├─────────┼──────────────────┼──────────────────┤\n");
    
    if (!deleted_indices) {
        for (int i = 0; i < original_size; i++) {
            printf("│ %7d │ %16.4f │ %16.4f │\n", i, original_array[i], ptr_array[i]);
        }
    } else {
        int new_index = 0;
        for (int i = 0; i < original_size; i++) {
            int is_deleted = 0;
            
            // Проверка, был ли удален этот элемент
            for (int j = 0; j < deleted_count; j++) {
                if (deleted_indices[j] == i) {
                    is_deleted = 1;
                    break;
                }
            }
            
            if (is_deleted) {
                printf("│ %7d │ %16.4f │ %22s │\n", i, original_array[i], "удалён");
            } else {
                printf("│ %7d │ %16.4f │ %16.4f │\n", i, original_array[i], ptr_array[new_index]);
                new_index++;
            }
        }
    }
    
    printf("└─────────┴──────────────────┴──────────────────┘\n");
    return 0;
}