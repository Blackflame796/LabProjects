#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int *pi, i = 5;
    float *pf, f = 2.1f;
    double *pd, d = 2.123456789;
    char *pc = "R";

    printf("Размеры указателей:\n");
    printf("pi = %lu\n", sizeof(pi));
    printf("pf = %lu\n", sizeof(pf));
    printf("pd = %lu\n", sizeof(pd));
    printf("pc = %lu\n\n", sizeof(pc));

    printf("Размеры данных:\n");
    printf("*pi = %lu (размер int)\n", sizeof(i));
    printf("*pf = %lu (размер float)\n", sizeof(f));
    printf("*pd = %lu (размер double)\n", sizeof(d));
    printf("*pc = %lu (размер char)\n", sizeof(*pc));
    
    return 0;
}