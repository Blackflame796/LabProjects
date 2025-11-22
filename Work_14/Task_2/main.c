#include <stdio.h>
#include <locale.h>

double sum_elements(double *ptr_array, int begin, int end) {
    double sum = 0.0;
    
    // Проверка корректности индексов
    if (begin < 0 || end < begin || ptr_array == NULL) {
        printf("Ошибка: некорректные индексы или указатель\n");
        return 0.0;
    }
    
    // Вычисление суммы элементов в заданном диапазоне
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    
    return sum;
}

int find_element(double *ptr_array, int n, double element) {
    // Проверка корректности входных данных
    if (ptr_array == NULL || n <= 0) {
        printf("Ошибка: некорректные входные данные\n");
        return -1;
    }
    
    // Поиск элемента в массиве
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i; // Возврат индекса найденного элемента
        }
    }
    
    return -1; // Элемент не найден
}

int main() {
    setlocale(LC_ALL,"RUS");
    double array[] = {1.5, 2.3, 4.7, 3.2, 5.9, 2.3, 6.1};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%.1f ", array[i]);
    }
    printf("\n\n");
    
    int begin = 1, end = 4;
    double sum_result = sum_elements(array, begin, end);
    printf("1. Сумма элементов от индекса %d до %d: %.2f\n", begin, end, sum_result);
    
    double search_element = 5.9;
    int found_index = find_element(array, size, search_element);
    
    if (found_index != -1) {
        printf("2. Элемент %.1f найден по индексу: %d\n", search_element, found_index);
    } else {
        printf("2. Элемент %.1f не найден в массиве\n", search_element);
    }
    
    double total_sum = sum_elements(array, 0, size - 1);
    printf("Сумма всех элементов массива: %.2f\n", total_sum);
    
    double not_found_element = 10.0;
    int not_found_index = find_element(array, size, not_found_element);
    printf("Поиск элемента %.1f: %s\n", not_found_element, 
           (not_found_index == -1) ? "не найден" : "найден");
    
    double duplicate_element = 2.3;
    int duplicate_index = find_element(array, size, duplicate_element);
    printf("Первое вхождение элемента %.1f: индекс %d\n", duplicate_element, duplicate_index);
    
    return 0;
}