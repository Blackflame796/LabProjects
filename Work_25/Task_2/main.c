#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void init_random()
{
    /* объявление необходимых переменных */
    int stime;
    long ltime;

    /* получает текущее календарное время */
    ltime = time(NULL);
    /* преобразование его к типу int */
    stime = (unsigned)ltime / 2;
    /* инициализация генератора */
    srand(stime);
}

int check_int_arrays_match(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0; // не совпадают
        }
    }
    return 1; // совпадают
}

int check_double_arrays_match(double arr1[], double arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0; // не совпадают
        }
    }
    return 1; // совпадают
}

int rand10(int mmax)
{
    if (mmax <= 0)
        return 1;
    int result = 1 + rand() % mmax;
    return result;
}

// Вещественное число в заданном диапазоне
double rand_double_range(double dmin, double dmax) {
    if (dmax <= dmin)
        return dmin;
    double scale = (double)rand() / RAND_MAX;
    double range = dmax - dmin; // длина диапазона
    double result = dmin + scale * range; // начало + случайная позиция
    return result;
}

// n целых чисел от 1 до mmax - возвращает указатель на массив
int* rand10_array(int n, int mmax)
{
    if (n <= 0 || n > MAX_SIZE)
        return NULL;

    // Выделяем память для массива
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand10(mmax);
    }
    return arr;
}

// n вещественных чисел в диапазоне от -dm до +dm - возвращает указатель на массив
double* rand_double_array(int n, double dm)
{
    if (n <= 0 || n > MAX_SIZE || dm < 0)
        return NULL;

    // Выделяем память для массива
    double *arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand_double_range(-dm, dm);
    }
    return arr;
}

// Функция только для вывода - остается void
void print_int_array(int arr[], int n)
{
    if (n <= 0 || arr == NULL)
        return;

    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}

// Функция только для вывода - остается void
void print_double_array(double arr[], int n)
{
    if (n <= 0 || arr == NULL)
        return;

    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %.3f ", arr[i]);
    }
    printf("]\n");
}

void compare_sequences()
{
    printf("\nСРАВНЕНИЕ ПОСЛЕДОВАТЕЛЬНОСТЕЙ:\n");

    // Создаем массивы через функции
    int *int_arr1 = rand10_array(5, 10);
    int *int_arr2 = rand10_array(5, 10);
    double *double_arr1 = rand_double_array(5, 1.0);
    double *double_arr2 = rand_double_array(5, 1.0);

    printf("Последовательность 1:\n");
    printf("Целые числа: ");
    print_int_array(int_arr1, 5);
    printf("Вещественные числа: ");
    print_double_array(double_arr1, 5);

    printf("\nПоследовательность 2:\n");
    printf("Целые числа: ");
    print_int_array(int_arr2, 5);
    printf("Вещественные числа: ");
    print_double_array(double_arr2, 5);

    // Проверка совпадения последовательностей
    int int_match = check_int_arrays_match(int_arr1, int_arr2, 5);
    int double_match = check_double_arrays_match(double_arr1, double_arr2, 5);

    printf("\nРезультат сравнения:\n");
    printf("Целые числа: %s\n", int_match ? "совпадают" : "не совпадают");
    printf("Вещественные числа: %s\n", double_match ? "совпадают" : "не совпадают");

    // Освобождаем память
    free(int_arr1);
    free(int_arr2);
    free(double_arr1);
    free(double_arr2);
}

int main()
{
    init_random();

    printf("1. Одиночные числа:\n");
    printf("\tЦелое число от 1 до 10: %d\n", rand10(10));
    printf("\tЦелое число от 1 до 100: %d\n", rand10(100));
    printf("\tВещественное число от 0.0 до 1.0: %.3f\n", rand_double_range(0.0, 1.0));
    printf("\tВещественное число от -5.0 до 5.0: %.3f\n", rand_double_range(-5.0, 5.0));

    printf("\n2. Массивы целых чисел:\n");
    int *int_arr1 = rand10_array(5, 10);
    printf("\t5 чисел от 1 до 10: ");
    print_int_array(int_arr1, 5);

    int *int_arr2 = rand10_array(10, 50);
    printf("\t10 чисел от 1 до 50: ");
    print_int_array(int_arr2, 10);

    printf("\n3. Массивы вещественных чисел:\n");
    double *double_arr1 = rand_double_array(5, 10.0);
    printf("\t5 чисел от -10.0 до 10.0: ");
    print_double_array(double_arr1, 5);

    double *double_arr2 = rand_double_array(10, 5.0);
    printf("\t10 чисел от -5.0 до 5.0: ");
    print_double_array(double_arr2, 10);

    printf("\n4. Вложенные вызовы функций:\n");
    printf("\tРазмер массива задан случайно (1-10): ");
    int random_size = rand10(10);
    int *random_size_arr = rand10_array(random_size, 20);
    printf("массив из %d элементов: ", random_size);
    print_int_array(random_size_arr, random_size);

    compare_sequences();

    // Освобождаем память
    free(int_arr1);
    free(int_arr2);
    free(double_arr1);
    free(double_arr2);
    free(random_size_arr);

    return 0;
}