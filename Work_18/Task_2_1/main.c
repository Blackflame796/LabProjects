#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"RUS");
    struct tm *mytime;
    time_t t;
    
    // Получение системного времени
    t = time(NULL);
    // Трансформация системного времени в структуру tm
    mytime = localtime(&t);

    printf("Московское время %02d:%02d:%02d\n", 
           mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    
    return 0;
}