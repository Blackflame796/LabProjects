#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

double calculate_a(double x);
double calculate_b(double x);

int main()
{
    setlocale(LC_ALL,"RUS");
    double x, y, a, b;
    double start = 2;
    double end = 4.1;
    double step;
    int choice;
    FILE *file;
    char filename[9] = "temp.txt";

    printf("Выберите режим работы с файлом:\n");
    printf("1) Запись в новый файл\n");
    printf("2) Дозапись в существующий файл\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        file = fopen(filename, "w");
        break;
    case 2:
        file = fopen(filename, "a");
        break;
    default:
        printf("Неверный выбор\n");
        return 1;
    }

    // Проверка успешного открытия файла
    if (file == NULL)
    {
        printf("Ошибка открытия файла %s\n", filename);
        return 1;
    }

    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);

    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным числом\n");
        fclose(file);
        return 1;
    }
    fprintf(file, "-----------------------------------\n");
    fprintf(file, "|    x    |       f(x)            |\n");
    fprintf(file, "-----------------------------------\n");

    for (x = start; x <= end; x += step)
    {
        // Проверка для логарифма (x > 0)
        if (x <= 0)
        {
            fprintf(file, "| %7.2f |   Ошибка: x <= 0      |\n", x);
            continue;
        }

        a = calculate_a(x);
        b = calculate_b(x);
        y = a - b;

        fprintf(file, "| %7.2f | %21.6f |\n", x, y);
    }
    fprintf(file, "-----------------------------------\n\n");

    fclose(file);

    printf("\nРезультаты успешно записаны в файл %s\n", filename);

    return 0;
}

double calculate_a(double x)
{
    double result = fabs(log10(x));
    return result;
}

double calculate_b(double x)
{
    double result = pow(x - 2, 2);
    return result;
}