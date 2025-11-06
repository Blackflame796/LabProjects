#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL,"RUS");
    int x = 0x12345678;
    unsigned char *a = (unsigned char *)&x;

    printf("Определение порядка байтов в системе:\n");
    printf("Число 0x%x в памяти: ", x);
    for (int i = 0; i < sizeof(x); i++)
    {
        printf("%02x ", a[i]);
    }
    printf("\n");

    int int_val = 12345;
    float float_val = 12345.0f;
    double double_val = 12345.0;

    printf("int: %d\n", int_val);
    printf("float: %f\n", float_val);
    printf("double: %lf\n", double_val);

    printf("\nПобайтовое представление:\n");

    printf("int (0x%x): ", int_val);
    unsigned char *int_bytes = (unsigned char *)&int_val;
    for (int i = 0; i < sizeof(int_val); i++)
    {
        printf("%02x ", int_bytes[i]);
    }
    printf("\n");

    printf("float (%f): ", float_val);
    unsigned char *float_bytes = (unsigned char *)&float_val;
    for (int i = 0; i < sizeof(float_val); i++)
    {
        printf("%02x ", float_bytes[i]);
    }
    printf("\n");

    printf("double (%lf): ", double_val);
    unsigned char *double_bytes = (unsigned char *)&double_val;
    for (int i = 0; i < sizeof(double_val); i++)
    {
        printf("%02x ", double_bytes[i]);
    }
    printf("\n");

    return 0;
}