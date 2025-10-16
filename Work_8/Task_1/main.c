#include <stdio.h>

int main()
{
    int m, n, s = 0;

    printf("Введите начальное значение m: ");
    scanf("%d", &m);
    printf("Введите конечное значение n: ");
    scanf("%d", &n);

    int k = 1;

    if (m <= n)
    {
        for (int i = m; i <= n; i++)
        {
            s += i;
            k++;
            printf("Выполнено %d раз\n", k);
        }
    }
    else {
        for (int i = m; i >= n; i--)
        {
            s += i;
            k++;
            printf("Выполнено %d раз\n", k);
        }
    }

    printf("Результат %d\n", s);

    return 0;
}