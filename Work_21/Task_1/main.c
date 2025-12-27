#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct Time
{
    int hour;
    int minute;
};

struct Flight
{
    int number;             // Номер авиарейса
    struct Time start_time; // Время вылета
    struct Time end_time;   // Время прилёта
    char destination[100];  // Направление
    char aircraft[50];      // Марка самолёта
    float distance;         // Расстояние (км)
    float speed;            // Cкорость
};

typedef struct Flight flight_t;

// Прототипы функций
void print_array(flight_t *flights, int size);
void print_flight(flight_t flight);
float calculate_time(struct Time dep, struct Time arr);

int main()
{
    flight_t *flights = NULL;
    int size = 0;
    int choice;
    
    size = 2;
    flights = malloc(size * sizeof(flight_t));
    if (flights == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    flights[0].number = 101;
    flights[0].start_time.hour = 8;
    flights[0].start_time.minute = 30;
    flights[0].end_time.hour = 10;
    flights[0].end_time.minute = 15;
    strcpy(flights[0].destination, "Moscow");
    strcpy(flights[0].aircraft, "Boeing");
    flights[0].distance = 1200.0;
    flights[0].speed = 800.0;
    
    flights[1].number = 202;
    flights[1].start_time.hour = 14;
    flights[1].start_time.minute = 45;
    flights[1].end_time.hour = 18;
    flights[1].end_time.minute = 20;
    strcpy(flights[1].destination, "Sochi");
    strcpy(flights[1].aircraft, "Airbus");
    flights[1].distance = 900.0;
    flights[1].speed = 600.0;

    do
    {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Добавить новые рейсы вручную\n");
        printf("2. Вывести все записи\n");
        printf("3. Изменить запись\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            {
                int count;
                printf("Сколько записей вы хотите добавить? ");
                scanf("%d", &count);
                
                if (count <= 0) {
                    printf("Неверное количество записей!\n");
                    break;
                }
                
                int new_size = size + count;
                flight_t *new_flights = realloc(flights, new_size * sizeof(flight_t));
                if (new_flights == NULL) {
                    printf("Ошибка выделения памяти!\n");
                    break;
                }
                flights = new_flights;
                
                for (int i = 0; i < count; i++)
                {
                    printf("\n=== Ввод данных авиарейса %d ===\n", size + 1);
                    
                    flight_t flight;

                    printf("Номер авиарейса: ");
                    scanf("%d", &flight.number);

                    printf("Время вылета (часы минуты): ");
                    scanf("%d %d", &flight.start_time.hour, &flight.start_time.minute);

                    printf("Время прилета (часы минуты): ");
                    scanf("%d %d", &flight.end_time.hour, &flight.end_time.minute);

                    printf("Направление: ");
                    scanf("%s", flight.destination);

                    printf("Марка самолета: ");
                    scanf("%s", flight.aircraft);

                    printf("Расстояние (км): ");
                    scanf("%f", &flight.distance);

                    float duration = calculate_time(flight.start_time, flight.end_time);
                    flight.speed = flight.distance / (duration > 0 ? duration : duration + 24);
                    
                    // Добавление в массив
                    flights[size] = flight;
                    size++;
                }
            }
            break;

        case 2:
            if (size > 0)
            {
                print_array(flights, size);
            }
            else
            {
                printf("Массив пуст!\n");
            }
            break;

        case 3:
            if (size > 0)
            {
                int index;
                print_array(flights, size);
                printf("\nВведите номер записи для изменения (1-%d): ", size);
                scanf("%d", &index);
                
                if (index < 1 || index > size) {
                    printf("Неверный номер записи!\n");
                } else {
                    printf("\n=== Изменение записи %d ===\n", index);
                    print_flight(flights[index-1]);

                    printf("\nВведите новые данные:\n");

                    int temp_int;
                    printf("Номер авиарейса [%d]: ", flights[index-1].number);
                    scanf("%d", &temp_int);
                    flights[index-1].number = temp_int;

                    printf("Время вылета [%02d:%02d] (часы минуты): ",
                           flights[index-1].start_time.hour, flights[index-1].start_time.minute);
                    int hour, minute;
                    scanf("%d %d", &hour, &minute);
                    flights[index-1].start_time.hour = hour;
                    flights[index-1].start_time.minute = minute;

                    printf("Время прилета [%02d:%02d] (часы минуты): ",
                           flights[index-1].end_time.hour, flights[index-1].end_time.minute);
                    scanf("%d %d", &hour, &minute);
                    flights[index-1].end_time.hour = hour;
                    flights[index-1].end_time.minute = minute;

                    char temp_str[100];
                    printf("Направление [%s]: ", flights[index-1].destination);
                    scanf("%s", temp_str);
                    strcpy(flights[index-1].destination, temp_str);

                    printf("Марка самолета [%s]: ", flights[index-1].aircraft);
                    scanf("%s", temp_str);
                    strcpy(flights[index-1].aircraft, temp_str);

                    float temp_float;
                    printf("Расстояние [%.0f]: ", flights[index-1].distance);
                    scanf("%f", &temp_float);
                    flights[index-1].distance = temp_float;

                    float duration = calculate_time(flights[index-1].start_time, flights[index-1].end_time);
                    if (duration > 0)
                    {
                        flights[index-1].speed = flights[index-1].distance / duration;
                    }
                    else
                    {
                        duration += 24;
                        flights[index-1].speed = flights[index-1].distance / duration;
                    }

                    printf("\nЗапись успешно изменена!\n");
                }
            }
            break;

        case 4:
            break;

        default:
            printf("Неверный выбор!\n");
        }

    } while (choice != 4);

    free(flights);
    flights = NULL;
    size = 0;
    
    return 0;
}

// Функция для вычисления времени в пути
float calculate_time(struct Time dep, struct Time arr)
{
    float hours = arr.hour - dep.hour;
    float minutes = arr.minute - dep.minute;
    float duration = hours + minutes / 60.0;

    if (duration < 0)
    {
        duration += 24.0;
    }

    return duration;
}

void print_array(flight_t *flights, int size)
{
    printf("\n=== СПИСОК АВИАРЕЙСОВ (Всего: %d) ===\n\n", size);
    printf("======================================================================================================================================================\n");
    printf("| №  | Номер  | Вылет | Прилёт | Направление                                       | Самолет                                  | Расстояние | Скорость |\n");
    printf("======================================================================================================================================================\n");

    for (int i = 0; i < size; i++)
    {
        flight_t *flight = &flights[i];
        printf("| %-2d | %-6d | %02d:%02d | %02d:%02d | %-50.50s | %-40s | %10.0f | %8.1f |\n",
               i + 1,
               flight->number,
               flight->start_time.hour, flight->start_time.minute,
               flight->end_time.hour, flight->end_time.minute,
               flight->destination,
               flight->aircraft,
               flight->distance,
               flight->speed);
    }
    printf("======================================================================================================================================================\n");
}

void print_flight(flight_t flight)
{
    printf("==========================================\n");
    printf("Номер авиарейса: %d\n", flight.number);
    printf("Время вылета: %02d:%02d\n", flight.start_time.hour, flight.start_time.minute);
    printf("Время прилета: %02d:%02d\n", flight.end_time.hour, flight.end_time.minute);
    printf("Направление: %s\n", flight.destination);
    printf("Марка самолета: %s\n", flight.aircraft);
    printf("Расстояние: %.0f км\n", flight.distance);
    printf("Скорость: %.1f км/ч\n", flight.speed);
    printf("==========================================\n");
}