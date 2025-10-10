#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    
    int n;
    
    printf("Введите трехзначное число: ");
    scanf("%d", &n);

    if (n < 100 || n > 999) {
        printf("Ошибка: введено не трёхзначное число.\n");
        return 1;
    }

    int last_digit = n % 10;
    
    int first_digit = n / 100;
    
    int sum_digits = n % 100 / 10 + n % 10 + n / 100;

    int reverse_n = last_digit * 100 + (n / 10 % 10) * 10 + first_digit;
    
    printf("Последняя цифра: %d\n", last_digit);
    printf("Первая цифра: %d\n", first_digit);
    printf("Сумма цифр: %d\n", sum_digits);
    printf("Число наоборот: %d\n", reverse_n);
    printf("\nПрограмма завершена. Нажмите Enter для выхода...");
    getchar();
    getchar();
    return 0;
}