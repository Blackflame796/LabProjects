#include <stdio.h>
#include <math.h>

double calculate_time(double H, double Vc, double S, double Vp) {
    /*
    H - высота самолета (м)
    Vc - скорость самолета (м/с)
    S - горизонтальное расстояние до цели (м)
    Vp - скорость ракеты (м/с)
    */

    // Квадраты скоростей для упрощения вычислений
    double Vc2 = Vc * Vc;
    double Vp2 = Vp * Vp;

    // Коэффициенты квадратного уравнения: a*t^2 + b*t + c = 0
    double a = Vp2 - Vc2;
    double b = 2 * S * Vc;
    double c = -(S * S + H * H);

    double D = b * b - 4 * a * c;

    double t1 = (-b + sqrt(D)) / (2 * a);
    double t2 = (-b - sqrt(D)) / (2 * a);

    double T = (t1 > 0) ? t1 : t2;

    return T;
}

int main() {
    double H = 5000;
    double Vc = 250;
    double S = 10000;
    double Vp = 500;

    printf("Высота: %.0f м\n", H);
    printf("Скорость самолета: %.0f м/с\n", Vc);
    printf("Расстояние: %.0f м\n", S);
    printf("Скорость ракеты: %.0f м/с\n\n", Vp);


    double T = calculate_time(H, Vc, S, Vp);

    printf("Время до поражения цели: %.3f секунд\n", T);

    return 0;
}