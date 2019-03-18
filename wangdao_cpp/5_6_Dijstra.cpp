#include <stdio.h>
#include <vector>
using namespace std;
struct E //邻接表中链表元素结构体
{
    int next; //直接相邻的结点
    int c;    //权值
};
vector<E> edge[101]; //邻接链表
bool mark[101];      //标记 true表示结点j的最短路径长度已经得到 该节点已经加入集合K
int Dis[101];        //距离向量 当mark为true时  表示已经得到的最短路径 否则 表示有从结点1出发经过已知的最短路径达到集合K中的某个结点 再经过一条边到达结点i的路径中最短的距离
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        while (m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            E tmp;
            tmp.c = c;
            tmp.next = b; //无向图
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        for (int i = 1; i <= n; i++)
        {
            Dis[i] = -1;
            mark[i] = false;
        }
        Dis[1] = 0;
        mark[1] = true;             //加入K
        int newP = 1;               //集合K中新加入的结点为1
        for (int i = 1; i < n; i++) //循环n-1次 按照最短路径递增的顺序确定其他n-1个点的最短路径长度
        {
            for (int j = 0; j < edge[newP].size(); j++) //遍历与该新加入集合k中的结点直接相邻的边
            {
                int t = edge[newP][j].next; //该边的另一个结点
                int c = edge[newP][j].c;    //长度
                if (mark[t] == true)        //若另一个结点也属于K 跳过
                    continue;
                if (Dis[t] == -1 || Dis[t] > Dis[newP] + c) //不可达 或 更短
                    Dis[t] = Dis[newP] + c;
            }
            int min = 123123123;
            for (int j = 1; j <= n; j++) //遍历所有的结点
            {
                if (mark[j] == true) //K 跳过
                    continue;
                if (Dis[j] == -1) //不可达 跳过
                    continue;
                if (Dis[j] < min) //若该结点经由1至k中的某点在经过一条边到达时距离小鱼当前最小值
                {
                    min = Dis[j]; //更新 新加入改点
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d\n", Dis[n]);
    }

    return 0;
}