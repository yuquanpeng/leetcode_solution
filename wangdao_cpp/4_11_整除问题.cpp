#include <stdio.h>
#include <string.h>
bool mark[1010];
int prime[1010];
int primeSize;
void init()
{
    primeSize = 0;
    for (int i = 2; i <= 1000; i++)
    {
        if (mark[i])
            continue;
        mark[i] = true;
        prime[primeSize++] = i;
        for (int j = i * i; j <= 1000; j += i)
            mark[j] = true;
    }
} //筛选出0-1000内所有的素数
int cnt[1010];
/**
 * cnt[i]用来表示prime[i]中做保存的素数在n阶乘中的因字数
 * 即n！分解素因数后 素因子prim[i]所对应的幂指数 可能为0
 **/
int cnt2[1010]; //表示prime所保存的素数在a中的因字数
int main()
{
    int n, a;
    init();
    while (scanf("%d%d", &n, &a) == 2)
    {
        for (int i = 0; i < primeSize; i++)
            cnt[i] = cnt2[i] = 0;           //计数器清零 为新的一次分解做准备
        for (int i = 0; i < primeSize; i++) //对n！分解素因数 遍历
        {
            int t = n; //用临时变量t保存n的值
            while (t)
            { //确定素数prime[i]在n中因子数
                cnt[i] += t / prime[i];
                t = t / prime[i];
            } //以此计算t/prime[i]^k 累加其值 直到t/prime[i]^k变为0
        }
        int ans = 123123123;                //答案初始值为一个大整数 为取最小值做准备
        for (int i = 0; i < primeSize; i++) //对a分解素因数
        {
            while (a % prime[i] == 0)
            {
                cnt2[i]++;
                a /= prime[i];
            } //计算a中素因数prime[i]对应的幂指数
            if (cnt2[i] == 0)
                continue;               //若该素数不能从a中分解到，即其对应幂指数为0 则其不影响整除性 跳过
            if (cnt[i] / cnt2[i] < ans) //计算素数prime[i]子啊两个数中因子数的商
                ans = cnt[i] / cnt2[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}
