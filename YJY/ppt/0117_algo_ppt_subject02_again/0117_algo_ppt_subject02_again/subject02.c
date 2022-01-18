#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40 //27인데 누가 20으로 갖다박음 ㅡㅡ

int map[MAX_SIZE][MAX_SIZE];
int count;

int check(int x, int y, int n);
void Fence(int x, int y, int n);

int main(void)
{
    int n;
    char file_name[10];

    printf("Enter File Name?");
    scanf("%s", &file_name);

    FILE* fp;
    fp = fopen(file_name, "r");
    fscanf(fp, " %d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &map[i][j]); //input 파일 안의 배열을 입력받음
        }
    }
    Fence(0, 0, n); //이걸 fence로 함수 때리면 count를 증가시킴
    printf("%d", count); //count 출력

    return 0;
}

void Fence(int x, int y, int n) //count++로 fence세우는 애(우물 정자 모양임)
{
    //if (n < 3) return; 
    if ((!check(x,y,n))) //1이 리턴되지 않는다, 즉 0이 리턴되면 이라는 뜻이니까 find!=map[i][j] 라는 뜻
    {
        count++; //같지 않다면 count를 1 증가시킨다
            for (int i = x; i < x + n; i += n / 3) //배열 x에, 즉 check에서 걸렸던 부분의 x에서 다시 시작함,  
                                                   //단 어디까지 시작하냐면 원래 check에서 받았던 n의 값 9에서 나누기 3을 한 3구간만큼 더 탐색함
                                                   //그러면 실제 구간 3만큼까지만 더 가게되므로 x가 인덱스 2인 경우 5블럭까지 탐색함
                                                   //왜냐면 우물정자 모양으로 fence가 나뉘므로 그 이상은 탐색하면 안됨
            {
                for (int j = y; j < y + n; j += n / 3) //얘도 위에 x랑 같은 원리임
                {
                    Fence(i, j, n / 3); //하고나면 다시 재귀로 돌려서 한 번 더 탐색
                }
            }
    }
    return 0; //끝나면 끝
}


int check(int x, int y, int n) //탐색하다가 다른 애 있는 지 확인하는 애
{
    int find = map[x][y]; //find=pivot, 배열을 find에다가 대입해서 여기다가 때려넣겠다, 근데 최대는 20,20이다. 이소리임

    for (int i = x; i < x + n; i++) //가로축 부분을 탐색시작 할건데, 이 때 시작 부분이 x부분 시작이니까 저렇게 시작하겠다. 
                                    //+n의 경우엔 저만큼 사이즈를 더 해줘야 나중에 그 구간의 블럭만큼 탐색함.
    {
        for (int j = y; j < y + n; j++) //세로축 부분 탐색 시작할건데 시작부분이 y니까 저렇게 시작하겠다,
                                        //만약에 y가 3번째 인덱스라면 거기서 계속 증가함
                                        //단 어디까지 하냐면 y인덱스에 입력받은 거에서 나누어진 크기인 n만큼만 플러스해서 계산해야함
        {
            if (find != map[i][j]) //pivot과 탐색되는 map의 배열 숫자가 같지 않다면 return 0 시켜서 이 함수를 빠져나오게함
                return 0;
        }
    }
    return 1; //같다면 1 출력
}

