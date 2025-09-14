#include <stdio.h>

int main() {
    int n = 3;
    int L = 33;
    int k = 2;
    int m = 2;
    double result = (double)n / L;

    int width = k + m + 2; // 2 + 2 + 2 = 6

    printf("%6d\n%6d\n%6.6s\n%-+6.2f\n",
           n,
           L,
           "_________",
           result);

    return 0;
}