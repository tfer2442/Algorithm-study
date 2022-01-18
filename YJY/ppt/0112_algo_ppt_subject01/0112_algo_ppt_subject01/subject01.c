#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

typedef struct NodeStruct
{
	struct NodeStruct* left; 
	struct NodeStruct* right; 
	int value; 
}Node;

Node* insert(Node* root, int value) 
{
	if (root == NULL) // root 제발 이 경우 빼먹지 마라 제발제발제발제발 등시나 생각해 제발
	{
		root = (Node*)malloc(sizeof(Node));
		root->left = root->right = NULL;
		root->value = value; //이 경우도 빼먹지마라 등시나 위에랑 안같다 등시나
		return root;
	}
	else //NULL이 아닌 경우
	{
		if (root->value > value) //현재 노드보다 값이 작은 경우
			root->left = insert(root->left, value); //왼쪽으로 삽입
		else //큰 경우
			root->right = insert(root->right, value); //오른쪽 삽입
	}
	return root; 
}

Node* search(Node* root, int value) 
{	
	Node* temp = root;
	
	while (1)
	{
		if (temp == NULL) //temp NULL이면 NULL return 시킴 -> 빼먹지마 등시나
		{
			return NULL;
		}
		if (temp->value == value) //value 값이랑 같으면 그대로 리턴
		{
			return temp;
		}
		else if (temp->value > value) //temp 값이 value 보다 더 크면 temp를 왼쪽에
		{
			temp = temp->left;
		}
		else // 걍 다 아니면 남은거 오른쪽 밖에 없음. 오른쪽으로 박으셈
		{
			temp = temp->right;
		}
	}
}

int main(void) 
{
	Node* root = NULL;
	char file_name[10]; 
	int n, m, num;
	int* find; //찾고자하는 숫자 배열
	
	FILE* fp; 

	printf("Enter File Name? ");
	scanf("%s", file_name); //파일 이름 입력 

	fp = fopen(file_name, "r"); //파일 open
	fscanf(fp, "%d %d", &n, &m); //n, m 값 불러오고
	find = malloc(sizeof(int) * n); //n수 만큼 배열을 동적할당 시킴!!!!!

	for (int i = 0; i < n; i++) //찾을 n개만큼 숫자 읽기
	{	
		fscanf(fp, "%d", &find[i]);
	}
	for (int i = 0; i < m; i++) //숫자 배열을 트리에 저장한다 
	{ 
		fscanf(fp, "%d", &num);
		root = insert(root, num); //root에 집어넣어집어넣으라고 등시나
	}

	for (int i = 0; i < n; i++) //찾을 숫자 찾기 
	{ 
		if (search(root, find[i]))
		{
			printf("Yes "); //있으면 yes
		}
		else {
			printf("No "); // 아니면 no
		}
	}
	return 0;
}
