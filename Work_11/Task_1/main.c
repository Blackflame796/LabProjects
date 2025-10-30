#include <stdio.h>
#include <locale.h>

#define N 10

int main()
{
    setlocale(LC_ALL, "RUS");

    float A[N];
    float original[N];

    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &A[i]);
        original[i] = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] == 0.0)
        {
            A[i] = i + 1;
        }
    }

    printf("\n┌─────────┬──────────────────┬──────────────────┐\n");
    printf("│ индекс  │ исходное значение│ новое значение   │\n");
    printf("├─────────┼──────────────────┼──────────────────┤\n");

    for (int i = 0; i < N; i++)
    {
        printf("│ %7d │ %16.2f │ %16.2f │\n", i + 1, original[i], A[i]);
    }

    printf("└─────────┴──────────────────┴──────────────────┘\n");

    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    printf("Среднее арифметическое элементов массива: %g\n", sum / N);
    return 0;
}