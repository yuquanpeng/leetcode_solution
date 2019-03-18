#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[501];
queue<int> Q;
int main()
{
    int inDegree[501];
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            inDegree[i] = 0;
            edge[i].clear();
        }
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            inDegree[b]++;
            edge[a].push_back(b);
        }
        while (Q.empty() == false)
        {
            Q.pop();
        }
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
                Q.push(i);
        int cnt = 0;
        while (Q.empty() == false)
        {
            int nowPoint = Q.front();
            Q.pop();
            cnt++;
            for (int i = 0; i < edge[nowPoint].size(); i++)
            {
                inDegree[edge[nowPoint][i]]--;
                if (inDegree[edge[nowPoint][i]] == 0)
                    Q.push(edge[nowPoint][i]);
            }
        }
        if (cnt == n)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}