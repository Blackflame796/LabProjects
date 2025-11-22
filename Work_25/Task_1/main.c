#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* объявление необходимых переменных */
    int stime;
    long ltime;

    /* получает текущее календарное время */
    ltime = time(NULL);
    /* преобразование его к типу int */
    stime = (unsigned) ltime/2;
    /* инициализация генератора */
    srand(stime);
    
    // int m = 1 + rand() % 10;
    
    // int k;
    
    // printf("Игра 'Угадай число'\n\n");
    // printf("Загадано число от 1 до 10. Попробуйте угадать: ");
    
    // scanf("%d", &k);
    
    // if (k == m) {
    //     printf("Вы угадали число %d!\n", m);
    // } else {
    //     printf("Вы не угадали. Было загадано число %d.\n", m);
    // }

    printf("ИГРА В КОСТИ\n\n");
    printf("Правила: бросаются два кубика. Выигрывает тот, у кого больше сумма.\n\n");
    
    // Бросок игрока
    int player_dice1 = 1 + rand() % 6;
    int player_dice2 = 1 + rand() % 6;
    int player_total = player_dice1 + player_dice2;
    
    // Бросок компьютера
    int computer_dice1 = 1 + rand() % 6;
    int computer_dice2 = 1 + rand() % 6;
    int computer_total = computer_dice1 + computer_dice2;
    
    // Вывод результатов
    printf("ВАШ БРОСОК:\n");
    printf("Первый кубик: %d\n", player_dice1);
    printf("Второй кубик: %d\n", player_dice2);
    printf("Сумма: %d\n\n", player_total);
    
    printf("БРОСОК КОМПЬЮТЕРА:\n");
    printf("Первый кубик: %d\n", computer_dice1);
    printf("Второй кубик: %d\n", computer_dice2);
    printf("Сумма: %d\n\n", computer_total);
    
    // Определение победителя
    printf("РЕЗУЛЬТАТ:\n");
    if (player_total > computer_total) {
        printf("Вы выиграли!\n");
    } else if (player_total < computer_total) {
        printf("Компьютер выиграл!\n");
    } else {
        printf("Ничья!\n");
    }
    
    return 0;
}