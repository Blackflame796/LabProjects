#include <stdio.h>
#include <locale.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    setlocale(LC_ALL,"RUS");

    int rows, cols;
    
    printf("Введите количество строк (1-%d): ", MAX_ROWS);
    scanf("%d", &rows);
    
    printf("Введите количество столбцов (1-%d): ", MAX_COLS);
    scanf("%d", &cols);
    
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Ошибка: размерность должна быть в диапазоне 1-%d для строк и 1-%d для столбцов!\n", 
               MAX_ROWS, MAX_COLS);
        return 1;
    }
    
    int array[MAX_ROWS][MAX_COLS];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = (j + 1) * 1000 + (i + 1);
        }
    }
    
    printf("\nСгенерированный массив:\n\n");
    
    printf("     ");
    for (int j = 0; j < cols; j++) {
        printf("%6d ", j + 1);
    }
    printf("\n");
    
    printf("     ");
    for (int j = 0; j < cols; j++) {
        printf("-------");
    }
    printf("\n");
    
    for (int i = 0; i < rows; i++) {
        printf("%2d | ", i + 1);  // Номер строки
        for (int j = 0; j < cols; j++) {
            printf("%6d ", array[i][j]);
        }
        printf("\n");
    }
    
    if (cols >= 2) {
        printf("\nЭлемент в предпоследнем столбце (строка 1): %d\n", array[0][cols - 2]);
    } else {
        printf("\nНедостаточно столбцов для предпоследнего элемента\n");
    }
    
    int search_value;
    printf("\nВведите значение для поиска на главной диагонали: ");
    scanf("%d", &search_value);
    
    int found_value = -1;
    int diagonal_size = (rows < cols) ? rows : cols;
    
    for (int i = 0; i < diagonal_size; i++) {
        if (array[i][i] == search_value) {
            found_value = array[i][i];
            break;
        }
    }
    
    if (found_value != -1) {
        printf("Значение %d найдено на главной диагонали\n", found_value);
    } else {
        printf("Значение %d не найдено на главной диагонали\n", search_value);
    }
    
    return 0;
}