#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>

// Функция для определения високосного года
int is_leap_year(int year);
// Функция для получения количества дней в месяце
int days_in_month(int month, int year);
// Функция для получения количества дней от начала года
int days_from_start_of_year(int day, int month, int year);

int main()
{
    setlocale(LC_ALL, "RUS");

    struct tm *mytime;
    time_t t;
    char str[512];

    // Получение текущего времени
    t = time(NULL);
    mytime = localtime(&t);

    int current_year = mytime->tm_year + 1900;
    int current_month = mytime->tm_mon;
    int current_day = mytime->tm_mday;
    int current_hour = mytime->tm_hour;
    int current_min = mytime->tm_min;
    int current_sec = mytime->tm_sec;
    int day_of_year = mytime->tm_yday;
    int pair_end_hour = 13;
    int pair_end_min = 55;
    int pair_start_hour = 12;
    int pair_start_min = 0;
    int year_short = current_year % 100;

    char *days[] = {"воскресенье", "понедельник", "вторник", "среда",
                    "четверг", "пятница", "суббота"};
    char *rom_months[] = {"I", "II", "III", "IV", "V", "VI",
                          "VII", "VIII", "IX", "X", "XI", "XII"};

    printf("День недели: %s\n", days[mytime->tm_wday]);

    sprintf(str, "%02d.%02d.%04d", current_day, current_month + 1, current_year);
    printf("Дата: %s\n", str);

    char *months[] = {"января", "февраля", "марта", "апреля", "мая", "июня",
                      "июля", "августа", "сентября", "октября", "ноября", "декабря"};
    sprintf(str, "%d %s", current_day, months[current_month]);
    printf("Дата: %s\n", str);

    printf("Сегодня %d-й день %d года\n", day_of_year + 1, current_year);

    int days_to_sunday = (7 - mytime->tm_wday) % 7;
    if (days_to_sunday == 0)
    {
        printf("Сегодня воскресенье\n");
    }
    else
    {
        int hours_to_sunday = days_to_sunday * 24 - current_hour;
        days_to_sunday = hours_to_sunday / 24;
        int hours_remainder = hours_to_sunday % 24;
        printf("До воскресенья %d дней и %d часов\n", days_to_sunday, hours_remainder);
    }

    int hours_since = current_hour - pair_start_hour;
    int mins_since = current_min - pair_start_min;

    if (mins_since < 0)
    {
        mins_since += 60;
        hours_since--;
    }

    if (hours_since < 0)
    {
        printf("Первая пара еще не началась\n");
    }
    else
    {
        printf("С первой пары прошло %d часов %d минут\n", hours_since, mins_since);
    }

    int days_in_current_year = is_leap_year(current_year) ? 366 : 365;
    // Количество дней до конца года
    int days_left_in_year = days_in_current_year - day_of_year - 1;
    // Количество месяцев до конца года
    int months_left = 12 - current_month - 1; // -1 потому что текущий месяц неполный

    int days_in_current_month = days_in_month(current_month, current_year);
    int days_left_in_month = days_in_current_month - current_day;

    if (days_left_in_year > 0)
    {
        printf("До Нового года осталось %d месяцев и %d дней\n",
               months_left, days_left_in_month);
    }
    else
    {
        printf("Сегодня Новый год!\n");
    }

    int current_total_minutes = current_hour * 60 + current_min;
    int end_total_minutes = pair_end_hour * 60 + pair_end_min;
    int mins_to_end = end_total_minutes - current_total_minutes;

    if (mins_to_end < 0)
    {
        printf("Пара уже закончилась\n");
    }
    else if (mins_to_end > 90)
    {
        printf("Пара ещё не началась\n");
    }
    else
    {
        int total_seconds_to_end = mins_to_end * 60 - current_sec;
        int mins_left = total_seconds_to_end / 60;
        int secs_left = total_seconds_to_end % 60;
        printf("До конца пары %d минут и %d секунд\n", mins_left, secs_left);
    }

    printf("До конца месяца %d дней, до конца года %d месяцев\n",
           days_left_in_month, months_left);

    sprintf(str, "%s %d", rom_months[current_month], current_year);
    printf("Месяц и год: %s\n", str);

    switch (current_month)
    {
        case 0: // Январь
            sprintf(str, "Зима %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день зимы", 31 + mytime->tm_yday + 1);
            break;
        case 1: // Февраль
            sprintf(str, "Зима %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день зимы", 31 + mytime->tm_yday + 1);
            break;
        case 2: // Март
            sprintf(str, "Весна %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день весны", mytime->tm_mday);
            break;
        case 3: // Апрель
            sprintf(str, "Весна %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день весны", 31 + mytime->tm_mday);
            break;
        case 4: // Май
            sprintf(str, "Весна %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день весны", 31 + 30 + mytime->tm_mday);
            break;
        case 5: // Июнь
            sprintf(str, "Лето %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день лета", mytime->tm_mday);
            break;
        case 6: // Июль
            sprintf(str, "Лето %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день лета", 30 + mytime->tm_mday);
            break;
        case 7: // Август
            sprintf(str, "Лето %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день лета", 30 + 31 + mytime->tm_mday);
            break;
        case 8: // Сентябрь
            sprintf(str, "Осень %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день осени", mytime->tm_mday);
            break;
        case 9: // Октябрь
            sprintf(str, "Осень %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день осени", 30 + mytime->tm_mday);
            break;
        case 10: // Ноябрь
            sprintf(str, "Осень %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день осени", 30 + 31 + mytime->tm_mday);
            break;
        case 11: // Декабрь
            sprintf(str, "Зима %02d", year_short);
            printf("%s\n", str);
            sprintf(str, "Идёт %d день зимы", mytime->tm_mday);
            break;
    }

    printf("%s\n", str);

    return 0;
}

int is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int days_in_month(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 && is_leap_year(year))
    { // февраль (индекс 1)
        return 29;
    }
    return days[month];
}

int days_from_start_of_year(int day, int month, int year)
{
    int total = 0;
    for (int i = 0; i < month; i++)
    {
        total += days_in_month(i, year);
    }
    return total + day - 1; // -1 так как день считается с 0
}