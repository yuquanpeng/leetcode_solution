#include <stdio.h>
int main()
{
    int outPutBuf[82][82];
    char a, b;
    int n;
    bool firstCase = true; //是否为第一组数据标志
    while (scanf("%d %c %c", &n, &a, &b))
    {
        if (firstCase == true)
            firstCase = false;
        else
            printf("\n");

        for (int i = 1, j = 1; i <= n; i += 2, j++) //从里到外输出圈
        {

            int x = n / 2 + 1;
            int y = x;
            x -= j - 1;
            y -= j - 1; //计算每个圈zuo上角的坐标
            char c = j % 2 == 1 ? a : b;
            for (int k = 1; k <= i; k++) //对当前圈进行赋值
            {
                outPutBuf[x + k - 1][y] = c;
                outPutBuf[x][y + k - 1] = c;
                outPutBuf[x + i - 1][y + k - 1] = c;
                outPutBuf[x + k - 1][y + i - 1] = c;
            }
        }
        if (n != 1)
        {
            outPutBuf[1][1] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}