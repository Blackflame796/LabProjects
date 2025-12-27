#include <stdio.h>
#include <math.h>
#include <locale.h>

// Объявление типа указателя на функцию
typedef double (*TFun)(double);

// Объявление прототипов функций
double Y(double x);
double V(double x);
double fun3(double x);
void t_rez(TFun f, double xn, double xk, double h, char* name);

int main()
{
    setlocale(LC_ALL,"RUS");
    double a, b, h;

    printf("Дано:\n");
    puts("Y(x) = 2*sin(πx)*sin(3πx) - 0.5");
    puts("При x < 0: V(x) = 1+2x/1+x^2");
    puts("При 0 ≤ x < 1: V(x) = (sin(x * √(1 + x)))^2");
    puts("При x ≥ 1: V(x) = (sin (x))^2 * e^(0.2 * x)");

    printf("Введите a: ");
    scanf("%lf", &a);
    printf("Введите b: ");
    scanf("%lf", &b);
    printf("Введите h: ");
    scanf("%lf", &h);
    
    printf("\n");
    t_rez(Y, a, b, h, "Y(x)");
    
    printf("\n");
    t_rez(V, a, b, h, "V(x)");
    
    return 0;
}

double Y(double x) {
    return 2 * sin(M_PI * x) * sin(3 * M_PI * x) - 0.5;
}

double V(double x) {
    if (x < 0) {
        return (1 + 2*x) / (1 + pow(x, 2));
    }
    else if (x >= 0 && x < 1) {
        return pow(sin(x), 2) * sqrt(1 + x);
    }
    else {
        return pow(sin(x), 2) * exp(0.2 * x);
    }
}

void t_rez(TFun f, double xn, double xk, double h, char* name) {
    printf("-----------------------------------------\n");
    printf("|     x        |       %s             |\n", name);
    printf("-----------------------------------------\n");
    for (double x = xn; x <= xk + h/2; x += h) {
        double result = f(x);
        printf("| %10.3f   | %14.6f         |\n", x, result);
    }
    
    printf("-----------------------------------------\n");
}