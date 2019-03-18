#include <stdio.h>
#define OFFSET 2000
int dp[101][4001];
int list[101]; //保存柑橘数量
#define INF 0x7fffffff
int main()
{
    int T;
    int cas = 0;
    scanf("%d", &T); //要处理的数据组数
    while (T-- != 0)
    {
        int n;
        scanf("%d", &n);
        bool HaveZero = false; //统计是否存在重量为0 的柑橘
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &list[++cnt]);
            if (list[cnt] == 0) //若当前柑橘重量为0
            {
                cnt--;
                HaveZero = true;
            }
        }
        n = cnt;
        for (int i = -2000; i <= 2000; i++)
            dp[0][i + OFFSET] = -INF; //初始化 为负无穷
        dp[0][0 + OFFSET] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = -2000; j <= 2000; j++)
            {
                int tmp1 = -INF, tmp2 = -INF; //分别记录当前柑橘放在第一堆或第二堆时转移得来的新值 若无法转移则为INF
                if (j + list[i] <= 2000 && dp[i - 1][j + list[i] + OFFSET] != -INF)
                    tmp1 = dp[i - 1][j + list[i] + OFFSET] + list[i];
                if (j - list[i] >= -2000 && dp[i - 1][j - list[i] + OFFSET] != -INF)
                    tmp2 = dp[i - 1][j - list[i] + OFFSET] + list[i];
                if (tmp1 < tmp2)
                    tmp1 = tmp2;
                if (tmp1 < dp[i - 1][j + OFFSET])
                    tmp1 = dp[i - 1][j + OFFSET];
                dp[i][j + OFFSET] = tmp1;
            }
        }
        printf("case %d: ", ++cas);
        if (dp[n][0 + OFFSET] == 0)
            puts(HaveZero == true ? "0" : "-1");
        else
            printf("%d\n", dp[n][0 + OFFSET] / 2);
    }

    return 0;
}