#include <stdio.h>
using namespace std;
#define N 10000001
int Tree[N];
int findBoot(int x)
{
    if (Tree[x] == -1)
        return x;
    else
    {
        int tmp = findBoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}
int sum[N]; //表示以结点i为根的树的个数 其中保存的数据仅当-1 有效
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i < N; i++)
        {
            Tree[i] = -1;
            sum[i] = 1;
        }
        while (n-- != 0)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findBoot(a);
            b = findBoot(b);
            if (a != b)
            {
                Tree[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = 1;
        for (int i = 1; i <= N; i++)
            if (Tree[i] == -1 & sum[i] > ans)
                ans = sum[i];
        printf("%d\n", ans);
    }
}