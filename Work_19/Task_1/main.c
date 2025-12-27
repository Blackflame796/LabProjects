#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL,"RUS");
    char fname[] = "number.txt";
    FILE *out;

    puts("Создание файла");

    if ((out = fopen(fname, "a")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }

    fprintf(out, "%g\n", 12.56);

    fclose(out);
    return 1;
}