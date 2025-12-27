#include <stdio.h>
#include <math.h>
#include <locale.h>

struct point {
    char name;
    float x;
    float y;
};

typedef struct point Point;

void put_point(Point z) {
    printf("Точка %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
    return sqrt((w.x - z.x) * (w.x - z.x) + (w.y - z.y) * (w.y - z.y));
}

Point midpoint(Point z, Point w, char name) {
    Point result;
    result.name = name;
    result.x = (z.x + w.x) / 2;
    result.y = (z.y + w.y) / 2;
    return result;
}

int get_quadrant(Point z) {
    if (z.x > 0 && z.y > 0) return 1; // первая четверть
    if (z.x < 0 && z.y > 0) return 2; // вторая четверть
    if (z.x < 0 && z.y < 0) return 3; // третья четверть
    if (z.x > 0 && z.y < 0) return 4; // четвертая четверть
    return 0; // точка на оси
}

// Вспомогательная функция для отображения названия четверти
void print_quadrant_info(Point z) {
    int quadrant = get_quadrant(z);
    
    printf("Точка ");
    put_point(z);
    
    switch (quadrant) {
        case 1:
            printf(" находится в I координатной четверти\n");
            break;
        case 2:
            printf(" находится во II координатной четверти\n");
            break;
        case 3:
            printf(" находится в III координатной четверти\n");
            break;
        case 4:
            printf(" находится в IV координатной четверти\n");
            break;
        case 0:
            printf(" лежит на координатной оси\n");
            break;
    }
}

int main() {
    setlocale(LC_ALL,"RUS");
    Point A, B, M;
    
    A.name = 'A';
    printf("Введите координаты точки A (x y): ");
    scanf("%f %f", &A.x, &A.y);
    
    B.name = 'B';
    printf("Введите координаты точки B (x y): ");
    scanf("%f %f", &B.x, &B.y);
    
    printf("\nВведенные точки:\n");
    put_point(A); printf("\n");
    put_point(B); printf("\n\n");
    
    printf("Расстояние между точками: ");
    put_point(A); printf(" и "); put_point(B);
    printf(" = %.2f\n\n", dist(A, B));
    
    M = midpoint(A, B, 'M');
    printf("Середина отрезка AB: ");
    put_point(M); printf("\n\n");
    
    printf("Определение координатных четвертей:\n");
    print_quadrant_info(A);
    print_quadrant_info(B);
    print_quadrant_info(M);
    
    return 0;
}