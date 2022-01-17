#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int[], int, int);

int main(void) {
	FILE* f1;
	char fname[20];
	int searchNum = 0, sampleNum = 0;
	int* arr;
	int i;
	int* sample;

	printf("Enter File Name? ");
	scanf("%s", fname);

	if (!(f1 = fopen("input1.txt", "r"))) {
		printf("파일을 열지 못했습니다.");
		exit(-1);
	}

	fscanf(f1, "%d%d", &searchNum, &sampleNum);

	arr = (int*)malloc(sizeof(int) * searchNum);
	sample = (int*)malloc(sizeof(int) * sampleNum);

	for (i = 0; i < searchNum; i++) {
		fscanf(f1, "%d", &arr[i]);
	}

	for (i = 0; i < sampleNum; i++) {
		fscanf(f1, "%d", &sample[i]);
	}

	

	for (i = 0; i < searchNum; i++) {
		if (binarySearch(sample, arr[i], sampleNum) == 1) printf("yes ");
		else printf("no ");
	}

	return 0;
}

int binarySearch(int sample[], int search, int sampleNum) {
	int cur = sampleNum / 2;
	float middle = cur / 2;

	while (1) {
		if (search == sample[cur]) return 1;
		if (middle < 0.5) return 0;

		if (search < sample[cur]) {
			cur = cur - middle - 0.5;
			middle = middle/2.0;
		}
		else if (search > sample[cur]) {
			cur = cur + middle +0.5;
			middle = middle/2.0;
		}
	}
}