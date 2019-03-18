#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> Q; //小顶堆
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        while (Q.empty() == false)
        {
            Q.pop(); //清除堆中元素
        }
        for (int i = 1; i <= n; i++)
        { //输入n个叶子结点权值
            int x;
            scanf("%d", &x);
            Q.push(x);
        }
        int ans = 0;
        while (Q.size() > 1)
        {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop(); //取出堆中两个最小的元素
            ans += a + b;
            Q.push(a + b);
        }
        printf("%d", ans);
    }

    return 0;
}