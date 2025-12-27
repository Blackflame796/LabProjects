#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Объявления функций
int *full_array(int *ptr_array, int size);
int put_array(int *ptr_array, int size);
int *sort_bubble(int *arr_ptr, int n);
int *sort_shaker(int *arr_ptr, int n);
int *sort_select(int *arr_ptr, int n);
int *sort_insert(int *arr_ptr, int n);

int main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Размер массива должен быть положительным числом!\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));

    if (!arr)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("\n==============================\n\n");

    for (int sort_type = 0; sort_type < 4; sort_type++)
    {
        arr = full_array(arr,size);

        printf("Исходный массив:\n");
        put_array(arr,size);
        
        
        switch(sort_type)
        {
            case 0:
                arr = sort_bubble(arr, size);
                printf("Пузырьковая сортировка:\n");
                put_array(arr,size);
                break;
            case 1:
                arr = sort_shaker(arr, size);
                printf("Шейкерная сортировка:\n");
                put_array(arr,size);
                break;
            case 2:
                arr = sort_select(arr, size);
                printf("Сортировка выбором:\n");
                put_array(arr,size);
                break;
            case 3:
                arr = sort_insert(arr, size);
                printf("Сортировка вставками:\n");
                put_array(arr,size);
                
                break;
        }
        printf("==============================\n\n");
    }

    free(arr);

    return 0;
}

// Пузырьковая сортировка
int *sort_bubble(int *arr_ptr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr_ptr[j] > arr_ptr[j + 1])
            {
                int temp = arr_ptr[j];
                arr_ptr[j] = arr_ptr[j + 1];
                arr_ptr[j + 1] = temp;
            }
        }
    }
    return arr_ptr;
}

// Шейкерная сортировка
int *sort_shaker(int *arr_ptr, int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        // Проход слева направо
        for (int i = left; i < right; i++)
        {
            if (arr_ptr[i] > arr_ptr[i + 1])
            {
                int temp = arr_ptr[i];
                arr_ptr[i] = arr_ptr[i + 1];
                arr_ptr[i + 1] = temp;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--)
        {
            if (arr_ptr[i] < arr_ptr[i - 1])
            {
                int temp = arr_ptr[i];
                arr_ptr[i] = arr_ptr[i - 1];
                arr_ptr[i - 1] = temp;
            }
        }
        left++;
    }
    return arr_ptr;
}

// Сортировка выбором
int *sort_select(int *arr_ptr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr_ptr[j] < arr_ptr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int temp = arr_ptr[i];
            arr_ptr[i] = arr_ptr[min_index];
            arr_ptr[min_index] = temp;
        }
    }
    return arr_ptr;
}

// Сортировка вставками
int *sort_insert(int *arr_ptr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr_ptr[i];
        int j = i;

        while (j > 0 && arr_ptr[j - 1] > temp)
        {
            arr_ptr[j] = arr_ptr[j - 1];
            j--;
        }

        arr_ptr[j] = temp;
    }
    return arr_ptr;
}

int *full_array(int *ptr_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr_array[i] = rand() % 1000; // числа от 0 до 999
    }
    return ptr_array;
}

int put_array(int *ptr_array, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%4d", ptr_array[i]);
        if ((i + 1) % 10 == 0 && i < size - 1)
            printf("\n ");
    }
    printf("]\n\n");
    return 0;
}