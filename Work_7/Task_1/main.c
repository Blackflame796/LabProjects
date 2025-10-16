#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    char c;
    printf("Введите символ: ");
    scanf("%c", &c);
    // switch (c)
    // {
    // case 'a':
    //     printf("Введено 'a'.\n");
    //     break;
    // case 'b':
    //     printf("Введено 'b'.\n");
    //     break;
    // default:
    //     printf("Неизвестный символ\n");
    // }
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        printf("Это цифра\n");
        break;
    default:
        printf("Это буква\n");
    }
    return 0;
}