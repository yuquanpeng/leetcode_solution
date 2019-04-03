//两个序列的中位数
int SearchMid(int A[], int B[], int n)
{
    int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1;
    int mid1, mid2;
    while (s1 < e1 && s2 < e2)
    {
        mid1 = (s1 + e1) / 2;
        mid2 = (s2 + e2) / 2;
        if (A[mid1] == B[mid2])
            return A[mid1];
        if (A[mid1] < B[mid2])
        {
            if ((s1 + e1) % 2 == 0)
                s1 = mid1;
            else
                s1 = mid1 + 1;
            e2 = mid2;
        }
        else
        {
            if ((s2 + e2) % 2 == 0)
                s2 = mid2;
            else
                s2 = mid2 + 1;
            e1 = mid1;
        }
    }
    if (A[s1] < B[s2])
        return A[s1];
    else
        return B[s2];
}
//折半查找
int BinSearch(int r[], int n, int k)
{
    int low = 0, hight = n - 1;
    int mid;
    while (low <= hight)
    {
        mid = (low + hight) / 2;
        if (k < r[mid])
            hight = mid - 1;
        else if (k > r[mid])
            low = mid + 1;
        else
            return mid;
    }
}
//选择k问题
int Partition(int r[], int low, int hight)
{
    int i = low, j = hight;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i++;
        }
        while (i < j && r[i] <= r[j])
            i++;
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            j--;
        }
    }
    return i;
}
int SelectMinK(int r[], int low, int hight, int k)
{
    int s;
    s = Partition(r, low, hight);
    if (s == k)
        return r[s];
    if (s > k)
        return SelectMinK(r, low, s - 1，k);
    else
        return SelectMinK(r, s + 1, hight, k);
}
//插入排序
void InsertSort(int r[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        r[0] = r[i];
        for (int j = i - 1; r[0] < r[j]; j--)
            r[j + 1] = r[j];
        r[j + 1] = r[0];
    }
}
//堆排序
void SiftHeap(int r[], int k, int n)
{
    int i = k;
    int j = 2 * i + 1;
    while (j < n)
    {
        if (j < n - 1 && r[j] < r[j + 1]) //比较i的左右孩子 取最大的
            j++;
        if (r[i] > r[j])
            break;
        else
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}
void HeapSort(int r[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        SiftHeap(r, i, n);
    for (int i = 1; i <= n - 1; i++)
    {
        int temp = r[i];
        r[i] = r[j];
        r[j] = temp;
        SiftHeap(r, 0, n - i);
    }
}
//淘汰赛冠军问题
char Game(char r[], int n)
{
    int i = n;
    while (i > 1)
    {
        i = i / 2;
        for (int j = 0; j < i; j++)
            if (Comp(r[j + i], r[j]))
                r[j] = r[j + 1];
    }
    return r[0];
}
//假币问题
int a[N];
void Coin(int low, int hight, int n)
{
    int num1, num2, num3;
    int add1, add2;

    if (n == 1)
        return low + 1;

    if (n % 3 == 0)
        num1 = num2 = n / 3;
    else
        num1 = num2 = n / 3 + 1;
    num3 = n - num1 - num2;

    for (int i = 0; i < num1; i++)
        add1 += a[low + i];
    for (int i = num1; i < num1 + num2; i++)
        add2 += a[low + i];

    if (add1 < add2)
        return Coin(low, low + num1 - 1, num1);
    else if (add1 > add2)
        return Coin(num1 + low, num1 + num2 + low - 1, num2);
    else
        return Coin(num2 + num1 + low, hight, num3);
}
