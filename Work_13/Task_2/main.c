#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char Name[50];
    char Snew[150] = "Привет, ";
    int pos = strlen(Snew);

    printf("Введите ваше имя: ");
    scanf("%s", Name);

    for(int i = 0; Name[i] != '\0'; i++) {
        if(isupper(Name[i])) {
            Snew[pos++] = Name[i];
            Snew[pos++] = Name[i];
            Snew[pos++] = Name[i];
        } else {
            Snew[pos++] = Name[i];
        }
    }
    
    Snew[pos++] = '!';
    Snew[pos] = '\0';

    printf("%s\n", Snew);

    return 0;
}