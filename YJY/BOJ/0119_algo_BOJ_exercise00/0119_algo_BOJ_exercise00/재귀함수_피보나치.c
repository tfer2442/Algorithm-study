#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	printf("���� �Է¹�������: ");
	scanf("%d", &n);

	printf("%d", fibonacci(n));

	return 0;
}

int fibonacci(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (x != 0 && x != 1) return x = fibonacci(x - 1) + fibonacci(x - 2);
	return fibonacci(x);
}