#include <stdio.h>
#include <locale.h>

void name() {
    puts("********************************************************");
    puts("*                                                      *");
    puts("*      Тема: Разработка консольного приложения         *");
    puts("*                                                      *");
    puts("* Группа: БИПТ-251                                     *");
    puts("* Выполнил: Сафонов Павел                              *");
    puts("*                                                      *");
    puts("********************************************************");
}

void date() {
    printf("   __    _   __    _   __   \n");
    printf(" |   |  | |    |  | |    |  \n");
    printf(" |   |  |_|    |  |_|    |  \n");
}

int main(void) {
    setlocale(LC_CTYPE, "RUS");
    name();
    date();
    return 0;
}