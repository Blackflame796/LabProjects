#include <stdio.h>
#include <math.h>

#define N 100

double calculate_value(double x)
{
    double a = fabs(log10(x));
    double b = pow(x - 2, 2);
    return a - b;
}

int main()
{
    double array[N];
    double positive_sum = 0.0, negative_sum = 0.0;
    int positive_count = 0, negative_count = 0;

    double start = 2.0;
    double end = 4.1;
    double step = (end - start) / (N - 1);

    double average_positive;

    for (int i = 0; i < N; i++)
    {
        double x = start + i * step;
        array[i] = calculate_value(x);

        if (array[i] > 0)
        {
            positive_sum += array[i];
            positive_count++;
        }
        else if (array[i] < 0)
        {
            negative_sum += array[i];
            negative_count++;
        }
    }

    if (positive_count > 0)
    {
        average_positive = positive_sum / positive_count;
    }
    else
    {
        average_positive = 0.0;
    }

    // printf("Шаг табуляции: %g\n",step); // 0.0212121
    printf("Имя массива: array\n");
    printf("Сумма положительных элементов массива: %.6f\n", positive_sum);
    printf("Сумма отрицательных элементов массива: %.6f\n", negative_sum);
    printf("Количество положительных элементов массива: %d\n", positive_count);
    printf("Количество отрицательных элементов массива: %d\n", negative_count);
    printf("Среднее арифметическое элементов массива: %g\n", average_positive);
    return 0;
}