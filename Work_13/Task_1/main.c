#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char Name[50];
    char Snew[70] = "ПРИВЕТ, ";

    printf("Введите ваше имя: ");

    scanf("%s", Name);

    strcat(Snew, Name);

    int current_length = strlen(Snew);
    int length_exclamations = 40 - current_length;
    
    for(int i = 0; i < length_exclamations; i++) {
        strcat(Snew, "!");
    }

    printf("%s\n", Snew);

    return 0;
}