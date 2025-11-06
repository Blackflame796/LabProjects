#include <stdio.h>
#include <locale.h>

int main()
{
    int *pa, x = 5;
    pa = &x;
    double *pd, d = 2.195678;
    pd = &d;
    char *pc = "r";
    long double *pld, ld = 8.123456789;
    pld = &ld;
    short unsigned int* psui, sui = 128;
    psui = &sui;
    int* pb, b = 1;
    pb = &b;
    puts("int:");
    printf("По адресу %p хранится *ptr=%d\n", pa, *pa);
    pa++;
    printf("По адресу %p хранится *ptr=%d\n", pa, *pa);
    pa--;
    printf("По адресу %p хранится *ptr=%d\n", pa, *pa);
    puts("double:");
    printf("По адресу %p хранится *ptr=%lf\n", pd, *pd);
    pd++;
    printf("По адресу %p хранится *ptr=%lf\n", pd, *pd);
    pd--;
    printf("По адресу %p хранится *ptr=%lf\n", pd, *pd);
    puts("char:");
    printf("По адресу %p хранится *ptr=%c\n", pc, *pc);
    pc++;
    printf("По адресу %p хранится *ptr=%c\n", pc, *pc);
    pc--;
    printf("По адресу %p хранится *ptr=%c\n", pc, *pc);
    puts("long double:");
    printf("По адресу %p хранится *ptr=%Lf\n", pld, *pld);
    pld++;
    printf("По адресу %p хранится *ptr=%Lf\n", pld, *pld);
    pld--;
    printf("По адресу %p хранится *ptr=%Lf\n", pld, *pld);
    puts("short unsigned int:");
    printf("По адресу %p хранится *ptr=%d\n", psui, *psui);
    psui++;
    printf("По адресу %p хранится *ptr=%d\n", psui, *psui);
    psui--;
    printf("По адресу %p хранится *ptr=%d\n", psui, *psui);
    puts("bool:");
    printf("По адресу %p хранится *ptr=%d\n", pb, *pb);
    pb++;
    printf("По адресу %p хранится *ptr=%d\n", pb, *pb);
    pb--;
    printf("По адресу %p хранится *ptr=%d\n", pb, *pb);
    return 0;
}