//埃及分数问题
void EgyptFraction(int A, int B)
{
    int E, R;
    do
    {
        E = B / A;
        cout << "1/" << E << "+";
        A = A * E - B;
        B = B * E;
        R = gcd(A, B);
        if (R > 1)
        {
            A /= R;
            B /= R;
        }
    } while (A > 1);
    cout << "1/" << B << endl;
    return;
}
//TSP 旅行家问题
//最近邻点策略
int TSP1(int arc[][], int w)
{
    int edgeCount = 0, TSPlength = 0;
    int min, u, v;
    int flag[n] = {0};
    u = w;
    flag[w] = 1;
    while (edgeCount < n - 1)
    {
        min = 100;
        for (int j = 0; j < n; j++)
            if (flag[j] == 0 && arc[u][j] != 0 && arc[u][j] < min)
            {
                v = j;
                min = arc[u][j];
            }
        TSPlength += arc[u][v];
        flag[v] = 1;
        edgeCount++;
        cout << u << "-->" << v << endl;
        u = v;
    }
    cout << v << "-->" << w << endl;
    return TSPlength + arc[u][w];
}
//图着色问题
void ColorGraph()
{
    int k = 0;
    int flag = 1;
    while (flag == 1)
    {
        k++;
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                color[i] = k;
                if (!judge(i))
                {
                    color[i] = 0;
                    flag = 1;
                }
            }
        }
    }
}
int judge(int i)
{
    for (int j = 0; j < n; j++)
        if (arc[i][j] == 1 && color[i] == color[j])
            return 0;
    return 1;
}
//
typedef struct
{
    int lowcost;
    int adjvex;
} Element;
void Prim(int arc[n][n], int w)
{
    int min;
    int k;
    Element shortEdge[10];
    for (int i = 0; i < n; i++)
    {
        shortEdge[i].lowcost = arc[w][i];
        shortEdge[i].adjvex = w;
    }
    shortEdge[w].lowcost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = 100;
        for (int j = 0; j < n; j++)
            if (shortEdge[j].lowcost != 0 && shortEdge[i].lowcost < min)
            {
                min = shortEdge[j].lowcost;
                k = j;
            }
    }
    cout << shortEdge[k].adjvex << "---" << k << endl;
    shortEdge[k].lowcost = 0;
    for (int j = 0; j < n; j++)
        if (arc[k][j] < shortEdge[j].lowcost)
        {
            shortEdge[j].lowcost = arc[k][j];
            shortEdge[k].adjvex = k;
        }
}
//背包问题(已排序)
int KnapSack(int w[], int v[], int n, int c)
{
    double x[10] = {0};
    int maxValue = 0;
    for (int i = 0; w[i] < c; i++)
    {
        x[i] = 1;
        maxValue += v[i];
        C -= w[i];
    }
    x[i] = (double)c / w[i];
    maxValue += x[i] * v[i];
    return maxValue;
}
//活动安排问题
int ActiveManage(int s[], int f[], int B[], int n)
{
    int j = 0;
    int count = 1;
    B[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] > f[i])
        {
            B[i] = 1;
            j = i;
            count++;
        }
        else
            B[i] = 0;
    }
    return count;
}
//多机调度问题
void MultiMachine(int t[], int n, int d[], int m)
{
    int S[3][7]; //假设三台机器处理七个作业
    int rear[3];
    for (int i = 0; i < m; i++)
    {
        S[i][0] = i;
        rear[i] = 0;
        d[i] = t[i];
    }
    for (int i = m; i < n; i++)
    {
        for (int j = 0, int k = 1; k < m; k++)
            if (d[k] < d[j])
                j = k;
        rear[j]++;
        S[j][rear[j]] = i;
        d[j] = d[j] + t[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << i << ":";
        for (int j = 0; S[i][j] >= 0; j++)
            cout << S[i][j] << " ";
        cout << endl;
    }
}