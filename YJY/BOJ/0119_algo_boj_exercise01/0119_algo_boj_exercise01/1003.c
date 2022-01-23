#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//시간초과 뜨는 재귀 방법ㅠㅠ
int dp(int x);
int count1 = 0; //0이 출력될 때 count1++ 로 1개 출력됐다고 해줌
int count2 = 0; //1이 출력될 때 count2++ 로 1개 출력됐다고 해줌

int main(void) //input 파일로 받는 거 아님. 이것 때문에 시간 많이 허비함. 문제 잘 볼 것
{
	int n = 0; //테스트 케이스 숫자임. 이 테스트 케이스만큼 반복을 돌 것임 
	scanf("%d", &n); //n으로 입력받음
	
	for (int i = 0; i < n; i++) //n만큼 돈다.
	{
		int t; //테스트 케이스 하나하나 입력받을 때 t로 입력받음
		scanf("%d", &t); 
		dp(t); //dp를 돌린다, 예시로 2를 받는다 치자
		printf("%d %d\n", count1, count2); //즉 테스트 케이스 2인경우 1 1 로 출력됨 
		count1 = 0; count2 = 0; //n만큼 돌려야하므로 i++해서 다음 테스트 케이스르 돌려야함
		                      //이때 초기화 안해주면 예시인 2에서 1 1 출력됐을 때 거기에 +되서 출력이 되버림.
	}
}

int dp(int x) //x에 2를 받음
{
	if (x == 0) count1++; //0이 아니므로 해당 없음
	else if (x == 1) count2++; //1이 아니므로 해당 없음
	else
	{
		return dp(x - 1) + dp(x - 2); //2이니까, dp(1)+dp(0)이고 dp가 다시 돌아서 1한번 체크, 0 한번 체크 됨 
	}
}

