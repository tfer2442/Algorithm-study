#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 20000  
int ary[INT_MAX][INT_MAX];
int count;
void partition(int row, int col, int size);
int is_same(int row, int col, int size);
int main()
{
    int size, i, j;
    FILE* fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &size);
    while (!feof(fp))
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                fscanf(fp, "%d ", &ary[i][j]);
            }
        }
    }
    partition(0, 0, size);
    printf("%d", count);



    return 0;
}
void partition(int row, int col, int size)
{
    if (size < 3)
    {
        return;
    }
    if (!is_same(row, col, size))
    {
        count++;
        size;
        for (int i = row; i < row+size; i += size / 3)
        {
            for (int j = col; j < col+size; j += size / 3)
            {
                partition(i, j, size / 3);
            }
        }
    }

}
int is_same(int row, int col, int size)
{
    int check = ary[row][col];
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (check != ary[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}