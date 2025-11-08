#include <stdio.h>
#include <math.h>

// Объявление типа указателя на функцию
typedef double (*TFun)(double);

// Объявление прототипов функций
double Y(double x);
double V(double x);
double fun3(double x);
void t_rez(TFun f, double xn, double xk, double h);

int main()
{
    double a, b, h;
    
    printf("Введите a: ");
    scanf("%lf",&a);
    printf("Введите b: ");
    scanf("%lf",&b);
    printf("Введите h: ");
    scanf("%lf",&h);
    
    puts("\n\t Function Y(x) = 2*sin(πx)*sin(3πx) - 0.5");
    t_rez(Y, a, b, h);
    
    puts("\n\t Function V(x) - piecewise function");
    t_rez(V, a, b, h);
    
    puts("\n\t Function fun3(x)");
    t_rez(fun3, a, b, h);
    
    return 0;
}

//--- Реализации функций пользователя ---
double Y(double x) {
    return 2 * sin(M_PI * x) * sin(3 * M_PI * x) - 0.5;
}

double V(double x) {
    if (x < 0) {
        return (1 + 2*x) / (1 + pow(x,2));
    }
    else if (x >= 0 && x < 1) {
        return pow(sin(x), 2) * sqrt(1 + x);
    }
    else {
        return pow(sin(x), 2) * exp(0.2 * x);
    }
}

double fun3(double x) {
    return log(tan(pow(x,2)));
}

void t_rez(TFun f, double xn, double xk, double h) {
    for (double x = xn; x <= xk; x += h) {
        printf(" x = %8.3f, y = %10.4f\n", x, f(x));
    }
}