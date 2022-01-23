#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 1000
int total_v, edg, v_start; //총 정점 개수, 간선 개수, 시작 정점 숫자
int graph[MAX_VERTEX][MAX_VERTEX]; //from to
int visited[MAX_VERTEX]; //to
int dfs(int total_v);

int main(void)
{
	int a, b; //지금 현재 위치한 정점
	scanf("%d", &total_v);
	scanf("%d", &edg);
	scanf("%d", &v_start);
 
	for (int i = 0; i < edg; i++) //간선개수만큼 돌림
	{
		scanf("%d", &a);
		scanf("%d", &b);
		graph[a][b] = graph[b][a] = 1; //현재 정점에서 from to 이든 to from이든 숫자 바뀌어도 간선개수 같음, 양방향이니까

		check_visited(); //visited[1,2,3,4] = 0임
		dfs(total_v); //total_v에 입력받은게 4임

		printf("%d", dfs(total_v));
	}
}

void check_visited() //맨처음에 간선개수 모조리 돌 때 일단 뭘하든 방문한 노드개수 default값은 0임, 그동안 방문한 게 없으니까
{
	for (int i = 1; i <= edg; i++) //간선개수 모조리 돈다
	{
		visited[i] = 0; //처음에 visited는 일단 어떤 정점이든 모조리 0임
	}
}

int dfs(int total_v) //total_v가 4임
{
	if (visited[total_v] = 1) //방문한 노드라면(0이 방문하지 않은거고 1이 방문한거임)  
		                      //초반에 4이니까 아님
	{
		printf("%d", total_v); //이렇게 출력해라 
	}

	for (int i = 1; i <= edg; i++) //if문을 실행했든 하지 않았든 간선개수만큼 돌림
	{
		if (graph[total_v][i] == 1 && visited[i] == 0) //graph배열에 입력받은 정점에서 i까지 갔는데 이때 간선이 1개로 현재 vertex와 연결되어 있고 방문하지 않았던 곳(0)이라면
		{
			visited[i] == 1; //i가 2,3,4인 경우가 나올거임 그러면 노드가 연결되어 있고 방문한곳이니까 1추가
			dfs(i); //dfs 돌려서 if로 출력하고 또 for문 돌림 
					//이때 total_v가 i가 됨
		}
	}
	//2 3은 안됨? 2 3 은 안되어야하는데 왜 이렇게 되면 되지? 어케 예시를 제외시키지? 아니 되나?ㅗㅗㅗㅗ
	//어차피 간선개수만큼 도니까 상관 없겠다
	//return 0;
}