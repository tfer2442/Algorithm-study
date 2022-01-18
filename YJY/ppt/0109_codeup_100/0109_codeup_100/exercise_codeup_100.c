#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//8
//int main(void)
//{
//    printf("\u250C\u252C\u2510\n");
//    printf("\u251C\u253C\u2524\n");
//    printf("\u2514\u2534\u2518\n");
//}

//15
//int main(void)
//{
//	float a;
//	scanf("%f", &a);
//	printf("%.2f", a);
//
//	return 0;
//}

//19
//int main(void)
//{
//	int year, month, day;
//	scanf("%d.%d.%d", &year, &month, &day);
//	printf("%04d.%02d.%02d", year, month, day);
//
//	return 0;
//}

//24
//int main(void)
//{
//	char d[20];
//	scanf("%s", d);
//	for (int i = 0; d[i] != '\0'; i++)
//	{
//		printf("\'%c\'\n", d[i]);
//	}
//
//	return 0;
//
//}

//25
//int main(void)
//{
//	int a,b,c,d,e;
//	scanf("%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e);
//	printf("[%d]\n", a * 10000);
//	printf("[%d]\n", b * 1000);
//	printf("[%d]\n", c * 100);
//	printf("[%d]\n", d * 10);
//	printf("[%d]\n", e * 1);
//
//	return 0;
//}

//28
//int main(void)
//{
//	unsigned int n;
//	scanf("%u", &n);
//	printf("%u", n);
//
//	return 0;
//}

//37
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	printf("%c", n); //아스키코드 문자로 출력하려면 "%c"로 입력
//
//	return 0;
//}

//59
//int main(void)
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d", ~a);
//
//	return 0;
//}

//90
//int main(void)
//{
//	float a, r, n, i;
//	scanf("%f %f %f", &a, &r, &n);
//	for (i = 1; i < n; i++)
//	{
//		a = a * r;
//	}
//	printf("%.0f", a);
//
//	return 0;
//}

//85
//int main(void)
//{
//	float h, b, s, c, r;
//	scanf("%f %f %f %f", &h, &b, &s, &c);
//	r = (h * b * s * c) / 8;
//	r = r / 1024;
//	r = r / 1024;
//	printf("%.1f MB", r);
//
//	return 0;
//
//}

//98
//int main()
//{
//    int h, w, n, l, d, x, y, i, j;
//    int a[101][101] = { 0, };
//    scanf("%d %d", &h, &w);
//    scanf("%d", &n);
//
//    for (i = 1; i <= n; i++)
//    {
//        scanf("%d %d %d %d", &l, &d, &x, &y);
//        if (l == 1)
//            if (a[x][y] == 0) a[x][y] = 1;
//        if (l != 1)
//        {
//            if (d == 0)
//                for (j = 1; j <= l; j++)
//                    a[x][y + j - 1] = 1;
//            else if (d == 1)
//                for (j = 1; j <= l; j++)
//                    a[x + j - 1][y] = 1;
//        }
//    }
//
//    for (i = 1; i <= h; i++)
//    {
//        for (j = 1; j <= w; j++)
//        {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//}

////99
int main()
{
    int map[11][11];
    int x = 2, y = 2;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (1) {
        if (map[x][y] == 0) 
        {
            map[x][y] = 9;
            y++;
        }
        if (map[x][y] == 1) 
        {
            y--;
            x++;
        }
        if (map[x][y] == 2) {
            map[x][y] = 9;
            break;
        }
        else if (map[x][y + 1] == 1 && map[x + 1][y] == 1)
        {
            if (map[x][y] == 0) 
            {
                map[x][y] = 9;
            }
            break;
        }
    }

    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}


