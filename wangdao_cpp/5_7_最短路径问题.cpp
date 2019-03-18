#include <stdio.h>
#include <vector>
using namespace std;
struct E
{
    int next;
    int c;
    int cost;
};
vector<E> edge[1001];
int dis[1001];
int cost[1001];
bool mark[1001];
int main()
{
    int n, m;
    int S, T;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        while (m--)
        {
            int a, b, c, cost;
            scanf("%d%d%d%d", &a, &b, &c, &cost);
            E tmp;
            tmp.c = c;
            tmp.cost = cost;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        scanf("%d%d", &S, &T);
        for (int i = 1; i <= n; i++)
        {
            dis[i] = -1;
            mark[i] = false;
        }
        dis[S] = 0;
        mark[S] = true;
        int newPoint = S;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < edge[newPoint].size(); j++)
            {
                int t = edge[newPoint][j].next;
                int c = edge[newPoint][j].c;
                int co = edge[newPoint][j].cost;
                if (mark[t] == true)
                    continue;
                if (dis[t] == -1 || dis[t] > dis[newPoint] + c || dis[t] == dis[newPoint] + c && cost[t] > cost[newPoint] + co)
                {
                    dis[t] = dis[newPoint] + c;
                    cost[t] = cost[newPoint] + co;
                }
            }
            int min = 123123123;
            for (int j = 1; j <= n; j++)
            {
                if (mark[j] == true)
                    continue;
                if (dis[j] == -1)
                    continue;
                if (dis[j] < min)
                {
                    min = dis[j];
                    newPoint = j;
                }
            }
            mark[newPoint] = true;
        }
        printf("%d %d", dis[T], cost[T]);
    }

    return 0;
}