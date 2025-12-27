#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"RUS");
	FILE* file;
	int sum = 0,a,cnt = 0;

	file = fopen("temp.txt","r");
	if (file == NULL)
		return -1;

	while (!feof(file))
	{
		fscanf(file, "%d", &a);
		sum += a;
		cnt++;
	}
	fclose(file);
	printf("Среднее арифметическое: %lf\n", (double)sum / cnt);
}