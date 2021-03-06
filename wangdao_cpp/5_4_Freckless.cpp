#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[101];
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
struct Edge
{
    int a, b;
    double cost;
    bool operator<(const Edge &A) const
    {
        return cost < A.cost;
    }
} edge[6000];
struct Point
{
    double x, y;
    double getDIstance(Point A)
    {
        double tmp = (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
        return sqrt(tmp);
    }
} list[101];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &list[i].x, &list[i].y);
        int size = 0; //抽象出边的总和
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                edge[size].a = i;
                edge[size].b = j;
                edge[size].cost = list[i].getDIstance(list[j]);
                size++;
            }
        }
        sort(edge, edge + n); //对边按照权值排序
        for (int i = 1; i <= n; i++)
            Tree[i] = -1;
        double ans = 0;
        for (int i = 0; i < size; i++)
        {
            int a = findBoot(edge[i].a);
            int b = findBoot(edge[i].b);
            if (a != b)
            {
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%2lf\n", ans);
    }

    return 0;
}
