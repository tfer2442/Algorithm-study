#define _CET_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 128

int map[MAX_SIZE][MAX_SIZE];
int white = 0;
int blue = 0;
int color;
int n = 0;

int main(void) //�굵 input���Ϸ� �޴� �� �ƴ�!!! ����!!
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	visit(0, 0, n);
	printf("%d\n%d", white, blue);

	return 0;
}

int visit(int x, int y, int n)
{
	int check = 1; //�� ��������
	               //check������ ���� Ȯ�����ִ� ����, �� ������ �ƴϸ� �ϳ��� �ٸ���

	if (map[x][y] == 1) //�迭 �� ���ڰ� 1�̸�
		color = 1; //color�� 1�� ���� 
	else //�迭 �� ���ڰ� 0�̸�
		color = 0; //color�� 0���� ����

	for (int i = x; i < x + n; i++)
	{
		if (!check) break; //check�� 0�̶� �Ҹ�
		                   //���� ���� �ƴ�, �ٸ� ���� Ƣ���, ���⼭ ������Ѿ���
		for (int j = y; j < y + n; j++)
		{
			if (map[i][j] != color) //�迭 ���ڿ� color���� ���ڰ� �ٸ���, �� Ž���ϴ� �迭�� �ٸ� ���� Ƣ��Դ�
			{
				check = 0; //0�� �ٸ����� �ִٴ� �Ҹ�
				break;
			}
		}
	}
	if (check) //check�� 1, �� ���ٸ�
	{
		if (color) blue++; //color�� 1�̴ϱ�, �� �ش� map�� ���簢���� ���δ� 1�̶� �Ҹ���, �̰� blue ī����
		else white++; //color�� 0, �� map�� 0�̶� �Ҹ��Ƿ� white++
	}
	else //�ٸ������� ������ ��� ������ �ٽ� ������
		//�̶� �׳� �����ִ� �� �ƴ϶� ���簢���� 4���� �ƴ� 1���� �̷���� ��쵵 �����ϱ� 4���� ������� ������ Ž���ؾ���
	{
		int temp = n / 2; //2��ŭ ������ ��� ������
		      
						  //�̷��� �������� ������ŭ�� �����ص��� �ʰ� �׳� ������ �� ������ �ݿ��� �� ���⿡ ���ư��� ����
		
		visit(x, y, temp);
		visit(x, y + temp, temp); //���÷� ��� 2��ŭ ������ ��� ���� �Ÿ� ����ؼ� ��� ����
		                          //�ٸ������� �ִ°�쿡 
								  //������, ����, �Ʒ�, �� ���� 
		visit(x + temp, y, temp);
		visit(x + temp, y + temp, temp);

	}
}

