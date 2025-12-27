#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>

void print_str(char *str);
int count_symbols(char *str);

int is_leap_year(int year);
int days_in_month(int month, int year);
int days_from_start_of_year(int day, int month, int year);

int main()
{
    struct tm *mytime;
    time_t t;
    char str[90];
    char *days[] = {"воскресенье", "понедельник", "вторник", "среда",
                    "четверг", "пятница", "суббота"};
    char *months[] = {"января", "февраля", "марта", "апреля", "мая", "июня",
                      "июля", "августа", "сентября", "октября", "ноября", "декабря"};
    char *rom_months[] = {"I", "II", "III", "IV", "V", "VI",
                          "VII", "VIII", "IX", "X", "XI", "XII"};

    setlocale(LC_ALL, "RUS");

    time(&t);
    mytime = localtime(&t);

    int current_year = mytime->tm_year + 1900;
    int current_month = mytime->tm_mon;
    int current_day = mytime->tm_mday;
    int current_hour = mytime->tm_hour;
    int current_min = mytime->tm_min;
    int current_sec = mytime->tm_sec;
    int day_of_year = mytime->tm_yday;
    int pair_end_hour = 10;
    int pair_end_min = 5;
    int pair_start_hour = 8;
    int pair_start_min = 30;
    int year_short = current_year % 100;

    sprintf(str, "Сегодня %s", days[mytime->tm_wday]);
    print_str(str);

    sprintf(str, "Сегодня %d.%d.%d",
            mytime->tm_mday, mytime->tm_mon + 1, 1900 + mytime->tm_year);
    print_str(str);

    sprintf(str, "Сегодня %d %s",
            mytime->tm_mday, months[mytime->tm_mon]);
    print_str(str);

    sprintf(str, "Сегодня %d-й день %d года",
            mytime->tm_yday + 1, 1900 + mytime->tm_year);
    print_str(str);

    int days_to_sunday = (7 - mytime->tm_wday) % 7;
    if (days_to_sunday == 0)
    {
        sprintf(str, "Сегодня воскресенье");
    }
    else
    {
        int hours_to_sunday = days_to_sunday * 24 - current_hour;
        days_to_sunday = hours_to_sunday / 24;
        int hours_remainder = hours_to_sunday % 24;
        sprintf(str, "До воскресенья %d дней и %d часов",
                days_to_sunday, hours_remainder);
    }
    print_str(str);

    int hours_since = current_hour - pair_start_hour;
    int mins_since = current_min - pair_start_min;

    if (mins_since < 0)
    {
        mins_since += 60;
        hours_since--;
    }

    if (hours_since < 0)
    {
        sprintf(str, "Первая пара еще не началась");
    }
    else
    {
        sprintf(str, "С первой пары прошло %d часов %d минут",
                hours_since, mins_since);
    }
    print_str(str);

    int days_in_current_year = is_leap_year(current_year) ? 366 : 365;
    int days_left_in_year = days_in_current_year - day_of_year - 1;
    int months_left = 12 - current_month - 1;

    int days_in_current_month = days_in_month(current_month, current_year);
    int days_left_in_month = days_in_current_month - current_day;

    if (days_left_in_year > 0)
    {
        sprintf(str, "До Нового года осталось %d месяцев и %d дней",
                months_left, days_left_in_month);
    }
    else
    {
        sprintf(str, "Сегодня Новый год!");
    }
    print_str(str);

    int current_total_minutes = current_hour * 60 + current_min;
    int end_total_minutes = pair_end_hour * 60 + pair_end_min;
    int mins_to_end = end_total_minutes - current_total_minutes;

    if (mins_to_end < 0)
    {
        sprintf(str, "Пара уже закончилась");
    }
    else if (mins_to_end > 90)
    {
        sprintf(str, "Пара ещё не началась");
    }
    else
    {
        int total_seconds_to_end = mins_to_end * 60 - current_sec;
        int mins_left = total_seconds_to_end / 60;
        int secs_left = total_seconds_to_end % 60;
        sprintf(str, "До конца пары %d минут и %d секунд",
                mins_left, secs_left);
    }
    print_str(str);

    sprintf(str, "До конца месяца %d дней, до конца года %d месяцев",
            days_left_in_month, months_left);
    print_str(str);

    sprintf(str, "Месяц %s и год %d",
            rom_months[mytime->tm_mon], 1900 + mytime->tm_year);
    print_str(str);

    switch (current_month)
    {
        case 0: // Январь
            sprintf(str, "Зима %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день зимы", 31 + current_day);
            break;

        case 1: // Февраль
            sprintf(str, "Зима %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день зимы", 31 + 31 + current_day);
            break;

        case 2: // Март
            sprintf(str, "Весна %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день весны", current_day);
            break;

        case 3: // Апрель
            sprintf(str, "Весна %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день весны", 31 + current_day);
            break;

        case 4: // Май
            sprintf(str, "Весна %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день весны", 31 + 30 + current_day);
            break;

        case 5: // Июнь
            sprintf(str, "Лето %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день лета", current_day);
            break;

        case 6: // Июль
            sprintf(str, "Лето %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день лета", 30 + current_day);
            break;

        case 7: // Август
            sprintf(str, "Лето %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день лета", 30 + 31 + current_day);
            break;

        case 8: // Сентябрь
            sprintf(str, "Осень %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день осени", current_day);
            break;

        case 9: // Октябрь
            sprintf(str, "Осень %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день осени", 30 + current_day);
            break;

        case 10: // Ноябрь
            sprintf(str, "Осень %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день осени", 30 + 31 + current_day);
            break;

        case 11: // Декабрь
            sprintf(str, "Зима %d", year_short);
            print_str(str);
            sprintf(str, "Идёт %d день зимы", current_day);
            break;
    }

    print_str(str);

    return 0;
}

int count_symbols(char *str)
{
    int count = 0;
    while (*str)
    {
        // В UTF-8 русские буквы начинаются с байтов 208 или 209
        if ((unsigned char)*str == 208 || (unsigned char)*str == 209)
        {
            str++; // Пропуск второго байта
        }
        count++;
        str++;
    }
    return count;
}

void print_str(char *str)
{
    int i;
    int symbols = count_symbols(str);
    int width = 60;

    for (i = 0; i < 10; i++)
        printf("*");

    int left_spaces = (width - symbols) / 2;
    for (i = 0; i < left_spaces; i++)
        printf(" ");

    printf("%s", str);

    int right_spaces = width - symbols - left_spaces;
    for (i = 0; i < right_spaces; i++)
        printf(" ");

    for (i = 0; i < 10; i++)
        printf("*");

    printf("\n");
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
    {
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
    return total + day - 1;
}