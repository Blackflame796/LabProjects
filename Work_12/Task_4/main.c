#include <stdio.h>
#include <locale.h>

int main()
{
    float array[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    float *ptr_a;

    printf("4.1 Проверка адресов массива\n");
    printf("array = %p\n", array);
    printf("&array[0] = %p\n", &array[0]);
    printf("&array = %p\n", &array);

    printf("4.2 Операции с указателем\n");
    
    ptr_a = array;
    printf("Начальное положение:\n");
    printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
    
    ptr_a++;
    printf("После ptr_a++:\n");
    printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
    
    ptr_a = ptr_a + 4;
    printf("После ptr_a + 4:\n");
    printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
    
    ptr_a = ptr_a - 2; 
    printf("После ptr_a - 2:\n");
    printf("ptr_a = %p, *ptr_a = %.1f\n\n", ptr_a, *ptr_a);

    printf("4.3 Проход по массиву с шагом 2\n");
    ptr_a = array;
    
    printf("Прямой проход с шагом 2:\n");
    for(int i = 0; i < 10; i += 2) {
        printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
        ptr_a += 2;
    }
    printf("\n");

    printf("4.4 Проход в обратном порядке\n");
    ptr_a = array + 9;
    
    printf("Обратный проход:\n");
    for(int i = 9; i >= 0; i--) {
        printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
        ptr_a--;
    }

    return 0;
}