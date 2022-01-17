#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//9
//0 0 0 1 1 1 2 2 2
//0 0 0 1 1 1 2 2 2
//0 0 0 1 1 1 2 2 2
//1 1 1 0 0 0 0 0 0
//1 1 1 0 0 0 0 0 0
//1 1 1 0 0 0 0 0 0
//0 1 2 0 1 2 0 1 2
//0 2 1 0 2 1 0 2 1
//1 1 1 0 1 1 2 2 2

//27
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//0 1 2 0 1 2 0 1 2 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3
//0 2 1 0 2 1 0 2 1 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3
//1 1 1 0 1 1 2 2 2 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 0 0 0 1 1 1 2 2 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 0 0 0 1 1 1 2 2 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 0 0 0 1 1 1 2 2 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 1 1 1 0 0 0 0 0 0
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 1 1 1 0 0 0 0 0 0
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 1 1 1 0 0 0 0 0 0
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 0 1 2 0 1 2 0 1 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 0 2 1 0 2 1 0 2 1
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 1 1 1 0 1 1 2 2 2
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//0 0 0 1 1 1 2 2 2 3 3 3 0 0 0 1 1 1 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//1 1 1 0 0 0 0 0 0 1 1 1 2 2 2 0 0 0 3 3 3 3 3 3 3 3 3
//0 1 2 0 1 2 0 1 2 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3
//0 2 1 0 2 1 0 2 1 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3
//1 1 1 0 1 1 2 2 2 0 0 0 1 1 1 2 2 2 3 3 3 3 3 3 3 3 3

int count = 0;
void Fence(int left, int right, int top, int bottom, int** arr);
void initFence(int*** arr2, int size, FILE* f2);

int main(void){
	FILE* f1;
	char fname1[20] = "\0";
	int size;
	int** arr;
	int i;
	int j;
	
	printf("Enter File Name? ");
	scanf("%s", fname1);

	if (!(f1 = fopen(fname1, "r"))) {
		printf("파일을 열지 못했습니다.");
		exit(-1);
	}

	fscanf(f1, "%d", &size);

	initFence(&arr, size, f1);

	Fence(0, size, 0, size, arr);
	printf("%d\n", count);

	return 0;
}

void Fence(int left, int right, int top, int bottom, int** arr) {
	int pivot, i, j, found = 0;
	int colmv, rowmv;

	if (left + 1 >= right || top + 1 >= bottom) return;

	pivot = arr[top][left];

	for (i = top; i < bottom && !(found); i++) {
		for (j = left; j < right; j++) {
			if (pivot != arr[i][j]) {
				count++; 
				found++;
				break;
			}
		}
	}

	colmv = (right - left) / 3;
	rowmv = (bottom - top) / 3;

	for (i = left; i < right; i += colmv) {
		for (j = top; j < bottom; j += rowmv) {
			Fence(i, i + colmv, j, j + colmv, arr);
		}
	}
}

void initFence(int*** arr2, int size, FILE* f2) {
	int i;
	int j;

	*arr2 = (int**)malloc(sizeof(int*) * size);

	for (i = 0; i < size; i++) {
		(*arr2)[i] = (int*)malloc(sizeof(int) * size);
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			fscanf(f2, "%d", &((*arr2)[i][j]));
		}
	}
}

