#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[][10]);
int main(void) {
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	i = 1;
	j = 1;
	
	if (arr[1][1] == 2) {
		arr[1][1] = 9;
		printarr(arr);
		return 0;
	}

	arr[1][1] = 9;

	while (1) {
		if (i == 8 && j==8) {
			break;
		}
		if (arr[i][j + 1] == 2) {
			j++;
			break;
		}

		if (arr[i][j + 1] == 0) {
			j++;
			arr[i][j] = 9;
		}
		else {
			if (arr[i + 1][j] == 2) {
				i++;
				break;
			}
			if (arr[i + 1][j] == 0) {
				i++;
				arr[i][j] = 9;
			}
		}
	}
	arr[i][j] = 9;
	printarr(arr);

	return 0;
}

void printarr(int arr[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}