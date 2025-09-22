#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define D 2.54
#define D_S 2.32166
#define _CRT_SECURE_NO_DEPRECATE

void task_1()
{
    int num1;
    int num2;
    puts("Введите первое число:");
    scanf("%d", &num1);
    printf("Введено число А: %d", num1);
    puts("Введите второе число:");
    scanf("%d", &num2);
    printf("Cумма: %d + %d = %d\n", num1, num2, num1 + num2);
    printf("Разность: %d - %d = %d\n", num1, num2, num1 - num2);
    printf("Произведение: %d * %d = %d\n", num1, num2, num1 * num2);
    printf("Частное от деления второго числа на первое: %d / %d = %d\n", num1, num2, num2 / num2);
    printf("Остаток от деления второго числа на первое: %d %% %d = %d\n", num1, num2, num2 % num1);
}

void task_2()
{
    int dym;
    float result_eng, result_esp, result_lit;

    puts("Введите количество дюймов:");
    scanf("%d", &dym);

    result_eng = D * dym;
    result_esp = D_S * dym;

    printf("%d дюймов равно:\n", dym);
    printf("Английских: %.2f см\n", result_eng);
    printf("Испанских: %.2f см\n", result_esp);
}

void task_2a()
{
    int sea_milles;
    float resultA;
    float resultB;

    printf("Введите количество морских миль:");
    scanf("%d", &sea_milles);
    resultA = sea_milles * 1.852;
    resultB = sea_milles * 1.689;
    printf("%d морская миль - это %.1f км \n%d сухопутных миль - это %.1f км",
           sea_milles, resultA, sea_milles, resultB);
}

void task_3()
{
    float a, b;
    
    printf("Введите два вещественных числа a и b: ");
    scanf("%f %f", &a, &b);
    
    // Вывод заголовка таблицы
    printf("_______________________________________________________________\n");
    printf("|        a * b        |        a+b        |        a-b        |\n");
    printf("---------------------------------------------------------------\n");
    
    printf("| %8.2g * %-8.2g | %8.2g + %-7.2g|%8.2g-%-8.2g  |\n", 
           a, b, a, b, a, b);
    printf("---------------------------------------------------------------\n");
    
    printf("| %-19.4g |%-19.4g|%-19.4g|\n", 
           a * b, a + b, a - b);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    // task_1();
    // task_2();
    // task_2a();
    task_3();
    // system("pause");
    return 0;
}