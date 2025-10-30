// Вариант 17
#include <stdio.h>
#include <locale.h>

int countDigits(long long num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int task_1(long long num)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 10 == 3)
            count++;
        num /= 10;
    }
    return count;
}

int task_2(long long num)
{
    int lastDigit = num % 10;
    int count = 0;
    while (num > 0)
    {
        if (num % 10 == lastDigit)
            count++;
        num /= 10;
    }
    return count;
}

int task_3(long long num)
{
    int count = 0;
    while (num > 0)
    {
        if ((num % 10) % 2 == 0)
            count++;
        num /= 10;
    }
    return count;
}

int task_4(long long num)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 10 > 5)
            count++;
        num /= 10;
    }
    return count;
}

int task_5(long long num)
{
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        if (digit % 2 != 0)
            sum += digit;
        num /= 10;
    }
    return sum;
}

int task_6(long long num)
{
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        if (digit >= 7)
            sum += digit;
        num /= 10;
    }
    return sum;
}

long long task_7(long long num)
{
    long long product = 1;
    int hasDigits = 0;
    while (num > 0)
    {
        int digit = num % 10;
        if (digit != 0)
        {
            product *= digit;
            hasDigits = 1;
        }
        num /= 10;
    }
    return hasDigits ? product : 0;
}

int task_8(long long num)
{
    int digitCount = countDigits(num);
    if (digitCount < 2)
        return 0;

    int secondDigit = 0, prelastDigit = 0;
    long long temp = num;
    int currentPos = digitCount;

    while (temp > 0)
    {
        if (currentPos == 2)
        {
            secondDigit = temp % 10;
            break;
        }
        temp /= 10;
        currentPos--;
    }

    temp = num;
    temp /= 10;
    prelastDigit = temp % 10;

    return secondDigit * prelastDigit;
}

int task_9(long long num)
{
    int sum = 0;
    long long temp = num / 10;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 0)
            sum += digit;
        temp /= 10;
    }
    return sum;
}

int task_10(long long num)
{
    long long temp = num;
    int prevDigit = -1;
    int foundSame = 0;

    while (temp > 0)
    {
        int currentDigit = temp % 10;
        if (currentDigit == prevDigit)
        {
            printf("%d%d ", currentDigit, currentDigit);
            foundSame = 1;
        }
        prevDigit = currentDigit;
        temp /= 10;
    }

    if (!foundSame)
        return 0;
    return 1;
}

int task_11(long long num)
{
    int digitCount = countDigits(num);
    if (digitCount % 2 == 0)
    {
        int sum1 = 0, sum2 = 0;
        int half = digitCount / 2;
        long long temp = num;
        int pos = 1;

        while (temp > 0)
        {
            int digit = temp % 10;
            if (pos <= half)
            {
                sum2 += digit;
            }
            else
            {
                sum1 += digit;
            }
            temp /= 10;
            pos++;
        }
        if (sum1 == sum2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int task_12(long long num)
{
    int sumEvenPos = 0, sumOddPos = 0;
    long long temp = num;
    int position = 1;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (position % 2 == 0)
        {
            sumEvenPos += digit;
        }
        else
        {
            sumOddPos += digit;
        }
        temp /= 10;
        position++;
    }
    return sumEvenPos * sumOddPos;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    long long num;
    char choice;
    int result_1, result_2, result_3, result_4, result_5, result_6, result_8, result_9, result_11, result_12;
    long long result_7;
    int result_10;
    do
    {
        printf("Введите число: ");
        scanf("%lld", &num);
        result_1 = task_1(num);
        printf("1) Количество цифр 3: %d\n", result_1);
        result_2 = task_2(num);
        printf("2) Повторений последней цифры (%lld): %d\n", num % 10, result_2);
        result_3 = task_3(num);
        printf("3) Количество четных цифр: %d\n", result_3);
        result_4 = task_4(num);
        printf("4) Количество цифр больших 5: %d\n", result_4);
        result_5 = task_5(num);
        printf("5) Сумма нечетных цифр: %d\n", result_5);
        result_6 = task_6(num);
        printf("6) Сумма цифр >= 7: %d\n", result_6);
        result_7 = task_7(num);
        printf("7) Произведение цифр (исключая 0): %lld\n", result_7);
        result_8 = task_8(num);
        printf("8) Произведение 2-й и предпоследней цифры: %d\n", result_8);
        result_9 = task_9(num);
        printf("9) Сумма четных цифр (исключая последнюю): %d\n", result_9);
        result_10 = task_10(num);
        printf("10) Рядом расположенные одинаковые цифры: ");
        if (result_10 == 1)
        {
            printf("да\n");
        }
        else
        {
            printf("нет\n");
        }
        result_11 = task_11(num);
        if (result_11 == -1)
        {
            printf("11) Число имеет нечетное количество цифр\n");
        }
        else
        {
            printf("11) Суммы половин числа ");
            if (result_11 == 1)
            {
                printf("равны\n");
            }
            else
            {
                printf("не равны\n");
            }
        }
        result_12 = task_12(num);
        printf("12) Произведение сумм четных и нечетных разрядов: %d\n", result_12);

        printf("\nПродолжить? (Да - y, Нет - n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    return 0;
}