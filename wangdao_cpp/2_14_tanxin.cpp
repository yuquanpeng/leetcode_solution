#include <stdio.h>
#include <algorithm>
using namespace std;
struct goods //表示可买物品
{
    double j; //该物品总重
    double f; //总价值
    double s; ///性价比
    bool operator<(const goods &A) const
    {
        return s > A.s;
    }
} buf[100];
int main()
{
    double m;
    int n;
    while (scanf("%lf%d", &m, &n) != EOF)
    {
        if (m == -1 && n == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f;
        }
        sort(buf, buf + n);
        int index = 0; //当前货物下标
        double ans = 0;
        while (m > 0 && index < n) //物品有剩余 钱有剩余
        {
            if (m > buf[index].f)
            {
                ans += buf[index].j;
                m -= buf[index].f;
            }
            else
            {
                ans += buf[index].j * m / buf[index].f;
                m = 0;
            }
            index++;
        }
        printf("%.3lf\n", ans);
    }

    return 0;
}