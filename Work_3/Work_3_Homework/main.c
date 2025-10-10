#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float diameter;
    float radius;
    float area;
    float volume;
    const double PI = 3.14;

    printf("Введите диаметр шара: ");
    scanf("%f", &diameter);

    if (diameter <= 0) {
        printf("Ошибка: диаметр должен быть положительным числом\n");
        return 1;
    }

    radius = diameter / 2.0;

    area = 4.0 * PI * (radius * radius);

    volume = (4.0 / 3.0) * PI * (radius * radius * radius);
    printf("Исходные параметры:\n");
    printf("\tДиаметр шара: %.3f\n", diameter);
    printf("Решение:\n");
    printf("\tРадиус шара: %.3f / 2 = %.3f\n",diameter, radius);
    printf("\tПлощадь поверхности: 4 * %.3f * (%.3f)^2 = %.3f\n",PI,radius, area);
    printf("\tОбъем: 4/3 * %.3f * (%.3f)^3 = %.3f\n",PI,radius, volume);

    return 0;
}
