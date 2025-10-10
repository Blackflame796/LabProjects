#include <stdio.h>
#include <locale.h>

void task_1a(double number) {
    int int_part = (int)number;
    double float_part = number - int_part;
    printf("Исходное число: %g\n",number);
    printf("Целая часть: %d\n",int_part);
    printf("Дробная часть: %g\n", float_part);
}

void task_1b(char c) {
    printf("Десятичный код символа \"%c\":%i\n",c,c);
    printf("Шестнадцатеричный код символа \"%c\":%x\n",c,c);
}

void task_1v(int number) {
    float n = (float)number;
    printf("1/%g = %g\n",n, 1 / n );
}

int main()
{
    setlocale(LC_ALL, "RUS");
    char c = '!';

    int i = 2;

    float f = 3.14f;

    double d = 5e-12;
    printf("%c\n",c);
    printf("%d\n",i);
    printf("%f",f);
    printf("%f\n",d);
    printf("Введите символ:");
    scanf("%s",&c);
    printf("Введите целое число:");
    scanf("%d",&i);
    printf("Введите число с плавающей точкой:");
    scanf("%f",&f);
    printf("Введите число двойной точности:");
    scanf("%lf",&d);
    task_1a(f);
    task_1a(d);
    task_1b(c);
    task_1v(i);
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}