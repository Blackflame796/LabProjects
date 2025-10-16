#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    double x;
    double result;
    
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    result = (x < 3.2) ? (pow(x, 4) + 9) : (54 * pow(x, 4) / (-5 * pow(x, 2) + 7));
    
    printf("F(%.2f) = %.6f\n", x, result);
    
    return 0;
}
