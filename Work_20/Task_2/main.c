#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE* file, * fileout;
    char name[100], fullnamein[150], fullnameout[150];
    double a;

    printf("Введите название файла: ");
    scanf("%s", name);
    sprintf(fullnamein, "%s.txt", name);
    sprintf(fullnameout, "%s_output.txt", name);

    file = fopen(fullnamein, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return -1;
    }

    fileout = fopen(fullnameout, "w");
    if (fileout == NULL) {
        printf("Ошибка создания нового файла\n");
        fclose(file);
        return -1;
    }

    while (fscanf(file, "%lf", &a) == 1)
    {
        if (a >= 0)
            fprintf(fileout, "положит\n");
        else
            fprintf(fileout, "отриц\n");
    }

    fclose(file);
    fclose(fileout);
    printf("Изменения успешно записаны в файл %s\n",fullnameout);
    
    return 0;
}