#include <stdio.h>

int main() {
    int n = 3;
    int L = 33;
    int k = 2;
    int m = 2;
    
    puts("Дано:");
    printf("%15d\n%15d\n%15.7s\nОтвет: \n%+13.2f\n", n,L, "________", (double)n/L);

    return 0;
}