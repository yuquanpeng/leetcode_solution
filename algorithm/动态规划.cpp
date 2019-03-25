int DataTower(int d[][], int n)
{
    int maxAdd[n][n] = {0};
    int path[n][n];

    for (int j = 0; j < n; j++)
        maxAdd[n - 1][j] = d[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            if (maxAdd[i + 1][j] > maxAdd[i + 1][j + 1])
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j];
                path[i][j] = j;
            }
            else
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j + 1];
                path[i][j] = j + 1;
            }

    printf("%d\n", d[0][0]);
    j = path[0][0];
    for (int i = 1; i < n; i++)
    {
        printf("%d", d[i][j]);
        j = path[i][j];
    }

    return maxAdd[0][0];
}
//多段图的最短路径问题
int arc[][];
int BackPath(int n)
{
    int cost[N], path[N];
    for (int i = 1; i < n; i++)
    {
        cost[i] = MAX;
        path[i] = -1;
    }
    cost[0] = 0;
    path[0] = -1;
    for (int j = 1; j < n; j++)
        for (int i = j - 1; i >= 0; i--)
            if (arc[i][j] + cost[i] < cost[j])
            {
                cost[j] = arc[i][j] + cost[i];
                path[j] = i;
            }
    cout << n - 1;
    int i = n - 1;
    while (path[i] >= 0)
    {
        cout << " " << path[i];
        i = path[i];
    }
    return cost[n - 1];
}
//多源点最短路径问题-Floyd算法
const int n = 10;
void Floyd(int arc[][], int dist[][])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = arc[i][j];
    for (int k = 0k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
//TSP问题 旅行家问题
/**
 * 输入：图的代价矩阵arc[n][n]
 * 输出：从顶点0出发经过所有顶点一次且仅一次再回到顶点0的最短路径长度
 * 1.初始化第0列：
 *  for(i=1;i<n;i++)
 *      d[i][0] = arc[i][0];
 * 2.依次处理每一个子集数组V[2 的 n-1 次方]
 *  for(i=1;i<n;i++)
 *      if(子集V[j]中不包含i)
 *          对V[j]中的每一个元素k，计算d[i][j] = min{arc[i][k]+d[k][j-1]};
 * 3.输出最短路径长度d[0][2 的 n-1 次方 -1]
 **/
//最长递增子序列问题
int InceraseOrder(int a[], int n)
{
    int L[10];                  //存储最长递增子序列的长度
    int x[10][10];              //存储对应的子序列
    for (int i = 0; i < n; i++) //初始化
    {
        L[i] = 1;
        x[i][0] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int max = 1;
        for (int j = i - 1; j >= 0; j--)
            if (a[j] < a[i] && max < L[j] + 1)
            {
                max = L[j] + 1;
                L[i] = max;
                for (int k = 0; k < max - 1; k++)
                    x[i][k] = x[j][k];
                x[i][max - 1] = a[i];
            }
    }
    int index;
    for (index = 0, i = 1; i < n; i++)
        if (L[index] < L[i])
            index = i;
    for (int i = 0; i < L[index]; i++)
        cout << x[index][i] << " ";
    return L[index];
}
//最长公共子序列问题
int CommonOrder(char x[], int m, char y[], int n, char z[])
{
    for (int j = 0; i <= n; j++)
        L[0][j] = 0;
    for (int i = 0; i <= m; i++)
        L[i][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if ((x[i] == y[j]))
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 1;
            }
            else if (L[i][j - 1] >= L[i - 1][j])
            {
                L[i][j] = L[i][j - 1];
                S[i][j] = 2;
            }
            else
            {
                L[i][j] = L[i - 1][j];
                S[i][j] = 3
            }
    i = m;
    j = n;
    int k = L[m][n];
    while (i > 0 && j > 0)
    {
        if (S[i][j] == 1)
        {
            z[k] = x[i];
            k--;
            i--;
            j--;
        }
        else if (S[i][j] == 2)
            j--;
        else
            i--;
    }
    for (k = 0; k < L[m][n]; k++)
        cout << z[k] << " ";
    return L[m][n];
}
//0-1背包问题
int KnapSack(int w[], int v[], int n, int C)
{
    for (int i = 0; i <= n; i++)
        V[i][0] = 0;
    for (int j = 0; j <= C; j++)
        V[0][j] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= C; j++)
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
    for (j = C, i = n; i > 0; i--) //求装入背包的物品
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    return V[n][C];
}
//最优二叉查找树
double OptimalBST(double p[], int n)
{
    int min, mink, sum;
    for (int i = 1; i <= n; i++)
    {
        C[i][i - 1] = 0;
        C[i][i] = p[i];
        R[i][i] = i;
    }
    C[n + 1][n] = 0;
    for (int d = 1; d < n; d++)
        for (int i = 1; i <= n - d; i++)
        {
            j = i + d;
            min = 1000;
            mink = i;
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += p[k - 1];
                if (C[i][k - 1] + C[k + 1][j] < min)
                {
                    min = C[i][k - 1] + C[k + 1][j];
                    mink = k;
                }
            }
            C[i][j] = min + sum;
            R[i][j] = mink;
        }
    return C[1][n];
}
//近似串匹配问题
int ASM(char p[], int m, chat T[], int n)
{
    for (int i = 1; i <= m; i++)
        D[i][0] = i;
    for (int j = 1; j <= n; j++)
        D[0][j] = j;
    for (j = 1; j <= n; j++)
        for (i = 1; i <= m; i++)
            if (P[i - 1] == T[j - 1])
                D[i][j] = min(D[i - 1][j - 1], D[i - 1][j] + 1, D[i][j - 1] + 1);
            else
                D[i][j] = min(D[i - 1][j - 1] + 1mD [i - 1][j] + 1, D[i][j - 1] + 1);
    return D[m][n];
}