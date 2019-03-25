//图着色问题
void GraphColor(int m)
{
    for (int i = 0; i < n; i++)
        color[i] = 0;
    int k = 0;
    while (k >= 0)
    {
        color[k] += 1;
        while (color[k] <= m)
        {
            if (ok(k))
                break;
            else
                color[k] += 1;
        }
        if (color[k] <= m && k == n - 1)
        {
            for (int i = 0; i < n; i++)
                cout << color[i] << " ";
            return;
        }
        if (color[k] <= m && k < n - 1)
            k += 1;
        else
            color[k--] = 0;
    }
}
int ok(int k)
{
    for (int i = 0; i < k; i++)
        if (arc[k][i] == 1 && color[k] == color[i])
            return 0;
    return 1;
}
//哈密顿回路问题
void Hamiton(int x[], int n)
{
    int visited[10];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        x[i] = 0;
    }
    x[0] = 0;
    visited[0] = 1;
    int k = 1;
    while (k >= 1)
    {
        x[k] += 1;
        while (x[k] < n)
        {
            if (visited[x[k]] == 0 && arc[x[k - 1]][x[k]] == 1)
                break;
            else
                x[k] += 1;
        }
        if (x[k] < n && k == n - 1 && arc[x[k]][0] == 1)
        {
            for (k = 0; k < n; k++)
                cout << x[k] + 1 << " ";
            return;
        }
        if (x[k] < n && k < n - 1)
        {
            visited[x[k]] = 1;
            k += 1;
        }
        else
        {
            visited[x[k]] = 0;
            k -= 1;
        }
    }
}
//n皇后问题
void Queen(int n)
{
    int k = 0;
    while (k >= 0)
    {
        x[k]++;
        while (x[k] < n && Place(k) == 1)
        {
            x[k]++;
        }
        if (x[k] < n && k == n - 1)
        {
            for (int i = 0; i < n; i++)
                cout << x[i] << " ";
            cout << endl;
            return;
        }
        if (x[k] < n && k < n - 1)
            k += 1;
        else
            x[k--] = -1;
    }
    cout << "NO" < endl;
}
int Place(int k)
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 1;
    return 0;
}
//批处理作业调度问题
int BatchJob(int a[], int b[], int n)
{
    int i, k;
    int x[10], sum1[10], sum2[10];
    int bestTime = 1000;
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        sum1[i] = 0;
        sum2[i] = 0;
    }
    sum1[0] = 0;
    sum2[0] = 0;
    int k = 1;
    while (k >= 1)
    {
        x[k] += 1;
        while (x[k] < n)
        {
            for (int i = 1; i < k; i++)
                if (x[i] == x[k])
                    break;
            if (i == k)
            {
                sum1[k] = sum1[k - 1] + a[x[k]];
                if (sum1[k] > sum2[k - 1])
                    sum2[k] = sum1[k] + b[x[k]];
                else
                    sum2[k] = sum2[k - 1] + b[x[k]];
                if (sum2[k] < bestTime)
                    break;
                else
                    x[k] = x[k] + 1;
            }
            else
                x[k] = x[k] + 1;
        }
        if (x[k] < n && k < n)
            k++;
        else
        {
            if (x[k] < n && k == n)
            {
                if (bestTime > sum2[k])
                {
                    bestTime = sum2[k];
                    for (int j = 1; j <= n; j++)
                        cout << x[j] << " ";
                    cout << bestTime << endl;
                }
                x[k] = -1;
                k--;
            }
        }
    }
    return bestTime;
}