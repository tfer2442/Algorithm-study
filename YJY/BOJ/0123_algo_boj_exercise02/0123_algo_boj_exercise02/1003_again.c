//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 50
//int map[MAX_SIZE][2];
//
//void dp(int x);
//
//int main(void)
//{
//    int n;
//    int t;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &t);
//        dp(t);
//    }
//    return 0;
//}
//
//void dp(int x) {
//    map[0][0] = 1;
//    map[0][1] = 0;
//    map[1][0] = 0; //1 0일 때 0 개수 0개임, 문제에서 그러라고 시킴
//    map[1][1] = 1;
//
//    for (int i = 2; i <= x; i++)
//    {
//        map[i][0] = map[i - 1][0] + map[i - 2][0];
//        map[i][1] = map[i - 1][1] + map[i - 2][1];
//    }
//    printf("%d %d\n", map[x][0], map[x][1]);
//}