#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void draw(int**arr, int l, int d, int x, int y);

int main(void) {
    int h, w;
    int** arr;
    int l;
    int n;
    int d;
    int x, y;
    int i;
    int j;

    scanf("%d%d", &h, &w);
    scanf("%d", &n);

    arr = (int**)malloc(sizeof(int*) * h);

    for (i = 0; i < h; i++) {
        arr[i] = (int*)malloc(sizeof(int) * w);
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            arr[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &l, &d, &x, &y);
        draw(arr, l, d, x, y);
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void draw(int** arr, int l, int d, int x, int y) {
    int i = 0;

    for (i = 0; i < l; i++) {
        if (d == 0) {
            arr[x-1][y-1 + i] = 1;
        }
        else {
            arr[x-1+i][y-1] = 1;

        }
    }
}
