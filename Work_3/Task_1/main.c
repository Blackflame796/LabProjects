#include <stdio.h>
#include <locale.h>

#define D 2.54
#define D_S 2.32166
#define _CRT_SECURE_NO_DEPRECATE 

void task_1() {
    int num1;
    int num2;
    puts("Введите первое число:");
    scanf("%d", &num1);
    printf("Введено число А: %d\n",num1);
    puts("Введите второе число:");
    scanf("%d", &num2);
    printf("Cумма: %d\n",num1 + num2);
    printf("Разность: %d\n", num1 - num2);
    printf("Произведение: %d\n", num1 * num2);
    printf("Частное от деления второго числа на первое: %d\n", num2 / num2);
    printf("Остаток от деления второго числа на первое: %d\n", num2 % num1);
}

void task_2() {
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

void task_3() {
    float a, b;
    
    printf("Введите два вещественных числа a и b: ");
    scanf("%f %f", &a, &b);
    
    // Верхняя граница таблицы
    printf("___________________________\n");
    printf("|   a * b   |   a+b    |   a-b    |\n");
    printf("-----------------------------------\n");
    
    // Строка с формулами
    printf("| %5.2f * %5.2f | %5.2f + %5.2f | %5.2f - %5.2f |\n", 
           a, b, a, b, a, b);
    printf("-----------------------------------\n");
    
    // Строка с результатами
    printf("|   %7.2f   |   %7.2f   |   %7.2f   |\n", 
           a * b, a + b, a - b);
}

int main() {
    setlocale(LC_ALL, "RUS");
    // task_1();
    // task_2();
    task_3();
    return 0;
}