#include <stdio.h>
#include <locale.h>

#define ROW 9
#define COL 9

#define A 10
#define B 10

int main()
{
    setlocale(LC_ALL, "RUS");
    // printf("\n");

    // for (int row = 1; row <= ROW; ++row)
    // {
    //     for (int col = 1; col <= row; ++col)
    //     {
    //         printf("%5d", col * row);
    //     }
    //     printf("\n");
    // }
    for (int row = 1; row <= A; row++)
    {
        for (int col = 1; col <= B; col++)
        {
            printf("%2d*%-2d=%-3d ", col, row, col * row);
        }
        printf("\n");
    }
    return 0;
}