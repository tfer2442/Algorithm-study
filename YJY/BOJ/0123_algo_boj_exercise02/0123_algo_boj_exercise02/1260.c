#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 1000
int total_v, edg, v_start; //�� ���� ����, ���� ����, ���� ���� ����
int graph[MAX_VERTEX][MAX_VERTEX]; //from to
int visited[MAX_VERTEX]; //to
int dfs(int total_v);

int main(void)
{
	int a, b; //���� ���� ��ġ�� ����
	scanf("%d", &total_v);
	scanf("%d", &edg);
	scanf("%d", &v_start);
 
	for (int i = 0; i < edg; i++) //����������ŭ ����
	{
		scanf("%d", &a);
		scanf("%d", &b);
		graph[a][b] = graph[b][a] = 1; //���� �������� from to �̵� to from�̵� ���� �ٲ� �������� ����, ������̴ϱ�

		check_visited(); //visited[1,2,3,4] = 0��
		dfs(total_v); //total_v�� �Է¹����� 4��

		printf("%d", dfs(total_v));
	}
}

void check_visited() //��ó���� �������� ������ �� �� �ϴ� ���ϵ� �湮�� ��尳�� default���� 0��, �׵��� �湮�� �� �����ϱ�
{
	for (int i = 1; i <= edg; i++) //�������� ������ ����
	{
		visited[i] = 0; //ó���� visited�� �ϴ� � �����̵� ������ 0��
	}
}

int dfs(int total_v) //total_v�� 4��
{
	if (visited[total_v] = 1) //�湮�� �����(0�� �湮���� �����Ű� 1�� �湮�Ѱ���)  
		                      //�ʹݿ� 4�̴ϱ� �ƴ�
	{
		printf("%d", total_v); //�̷��� ����ض� 
	}

	for (int i = 1; i <= edg; i++) //if���� �����ߵ� ���� �ʾҵ� ����������ŭ ����
	{
		if (graph[total_v][i] == 1 && visited[i] == 0) //graph�迭�� �Է¹��� �������� i���� ���µ� �̶� ������ 1���� ���� vertex�� ����Ǿ� �ְ� �湮���� �ʾҴ� ��(0)�̶��
		{
			visited[i] == 1; //i�� 2,3,4�� ��찡 ���ð��� �׷��� ��尡 ����Ǿ� �ְ� �湮�Ѱ��̴ϱ� 1�߰�
			dfs(i); //dfs ������ if�� ����ϰ� �� for�� ���� 
					//�̶� total_v�� i�� ��
		}
	}
	//2 3�� �ȵ�? 2 3 �� �ȵǾ���ϴµ� �� �̷��� �Ǹ� ����? ���� ���ø� ���ܽ�Ű��? �ƴ� �ǳ�?�ǤǤǤ�
	//������ ����������ŭ ���ϱ� ��� ���ڴ�
	//return 0;
}