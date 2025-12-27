#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 7
#define COLS 7
#define MIN_VALUE -10
#define MAX_VALUE 10

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // Инициализация генератора случайных чисел
    
    int array[ROWS][COLS];
    int array_t[COLS][ROWS];
    
    puts("Исходный массив:");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
    
    puts("Транспонированный массив:");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array_t[j][i] = array[i][j];
        }
    }
    
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%4d", array_t[i][j]);
        }
        printf("\n");
    }
    
    int negativeSum = 0;
    for (int j = 0; j < COLS; j++) {
        int element = array[4][j];
        if (element < 0) {
            negativeSum += element;
        }
    }
    printf("Сумма отрицательных элементов пятой строки: %d\n", negativeSum);
    
    int pairs_count = 0;
    
    // Проверка в строках
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            if (array[i][j] == array[i][j + 1]) {
                pairs_count++;
            }
        }
    }
    
    // Проверка в столбцах
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS - 1; i++) {
            if (array[i][j] == array[i + 1][j]) {
                pairs_count++;
            }
        }
    }
    printf("Число пар одинаковых соседних элементов: %d\n", pairs_count);

    // Поиск координат максимального элемента
    int maxVal = array[0][0];
    int maxRow = 0;
    int maxCol = 0;
    
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            int current = array[i][j];
            if (current >= maxVal) {
                maxVal = current;
                maxRow = i;
                maxCol = j;
            }
        }
    }
    
    printf("Координаты максимального элемента: %d строка, %d столбец\n", 
           maxRow + 1, maxCol + 1);
    printf("Значение максимального элемента: %d\n", array[maxRow][maxCol]);
    
    return 0;
}