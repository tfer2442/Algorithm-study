#define _CET_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 128

int map[MAX_SIZE][MAX_SIZE];
int white = 0;
int blue = 0;
int color;
int n = 0;

int main(void) //얘도 input파일로 받는 거 아님!!! 제발!!
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
	int check = 1; //다 같은색임
	               //check변수는 색을 확인해주는 변수, 다 같은지 아니면 하나라도 다른지

	if (map[x][y] == 1) //배열 속 숫자가 1이면
		color = 1; //color를 1로 저장 
	else //배열 속 숫자가 0이면
		color = 0; //color는 0으로 저장

	for (int i = x; i < x + n; i++)
	{
		if (!check) break; //check가 0이란 소리
		                   //같은 색이 아님, 다른 색이 튀어나옴, 여기서 종료시켜야함
		for (int j = y; j < y + n; j++)
		{
			if (map[i][j] != color) //배열 숫자와 color저장 숫자가 다르다, 즉 탐색하던 배열과 다른 색이 튀어나왔다
			{
				check = 0; //0은 다른색이 있다는 소리
				break;
			}
		}
	}
	if (check) //check가 1, 다 같다면
	{
		if (color) blue++; //color가 1이니까, 즉 해당 map의 정사각형이 전부다 1이란 소리임, 이게 blue 카운팅
		else white++; //color가 0, 즉 map이 0이란 소리므로 white++
	}
	else //다른색깔이 있으면 재귀 돌려서 다시 나눠줌
		//이때 그냥 나눠주는 게 아니라 정사각형이 4개가 아닌 1개로 이루어진 경우도 있으니까 4가지 방면으로 나누어 탐색해야함
	{
		int temp = n / 2; //2만큼 나눠서 재귀 돌려줌
		      
						  //이렇게 나누어진 공간만큼을 저장해두지 않고 그냥 나누면 그 전꺼를 반영할 수 없기에 돌아가지 않음
		
		visit(x, y, temp);
		visit(x, y + temp, temp); //예시로 들면 2만큼 나눠서 재귀 돌린 거를 계속해서 재귀 돌림
		                          //다른색깔이 있는경우에 
								  //오른쪽, 왼쪽, 아래, 위 전부 
		visit(x + temp, y, temp);
		visit(x + temp, y + temp, temp);

	}
}

