//数字旋转方阵
void Full(int number, int begin, int size)
{
    if (size == 0)
        return;
    if (size == 1)
    {
        data[begin][begin] = number;
        return;
    }
    int i = begin, j = begin;
    for (int k = 0; k < size - 1; k++)
    {
        data[i][j] = number;
        number++;
        i++;
    }
    for (int k = 0; k < size - 1; k++)
    {
        data[i][j] = number;
        number++;
        j++;
    }
    for (int k = 0; k < size - 1; k++)
    {
        data[i][j] = number;
        number++;
        i--;
    }
    for (int k = 0; k < size - 1; k++)
    {
        data[i][j] = number;
        number++;
        j--;
    }
    Full(number, begin + 1; size - 2);
}
//归并排序
void Merge(int r[], int r1[], int s, int m, int t)
{
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    }
    while (i <= m)
    {
        r1[k++] = r[i++];
    }
    while (j <= t)
    {
        r1[k++] = r[j++];
    }
}
void MergeSort(int r[], int s.int t)
{
    int m, r1[1000];
    if (s == t)
        return;
    else
    {
        m = (s + t) / 2;
        MergeSort(r, s, m);
        MergeSort(r, m + 1, t);
        Merge(r, r1, s, m, t);
        for (int i = 1; i <= t; i++)
            r[i] = r1[i];
    }
}
//快速排序
int Partition(int r[], int first, int end)
{
    int i = first, j = end;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
        {
            j--;
        }
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i++;
        }
        while (i < j && r[i] <= r[j])
        {
            i++;
        }
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
void QuickSort(int r[], int first, int end)
{
    int pivot;
    if (first < end)
    {
        pivot = Partition(r, first, end);
        QuickSort(r, first, pivot - 1);
        QuickSort(r, pivot + 1, end);
    }
}

//最大子段和问题
int MaxSum(int a[], int left, int right)
{
    int sum = 0, midSum = 0, leftSum = 0, rightSum = 0;
    int center = 0, s1 = 0, s2 = 0, lefts = 0, rights = 0;
    if (left == right)
        sum = a[left];
    else
    {
        center = (left + right) / 2;
        leftSum = MaxSum(a, left, center);
        rightSum = MaxSum(a, center - 1, right);

        for (int i = center; i >= left; i--)
        {
            lefts += a[i];
            if (lefts > s1)
                s1 = lefts;
        }
        for (int i = center + 1; j < right; j++)
        {
            rights += a[i];
            if (rights > s2)
                s2 = rights;
        }
        midSum = s1 + s2;

        if (midSum < leftSum)
            sum = leftSum;
        else
            sum = midSum;
        if (sum < rightSum)
            sum = rightSum;
    }
    return sum;
}
//棋盘覆盖问题
int t = 0; //L型骨牌编号
int board[size][size];
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    int s, t1; //t1表示本次覆盖所用L型骨牌的编号
    if (size == 1)
        return;
    t1 = ++t;
    s = size / 2;                   //划分棋牌
    if (dr < tr + s && dc < tc + s) //左上角
        ChessBoard(tr, tc, dr, dc, s);
    else
    {
        board[tr + s - 1][tc + s - 1] = t1;
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    if (dr < tr + s && dc >= tc + s) //右上角
        ChessBoard(tr, tc + s, dr, dc, s);
    else
    {
        board[tr + s - 1][tc + s] = t1;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }
    if (dr >= tr + s && dc < tc + s) //左下角
        ChessBoard(tr + s, tc, dr, dc, s);
    else
    {
        board[tr + s][tc + s - 1] = t1;
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }
    if (dr >= tr + s && dc >= tc + s) //右下角
        ChessBoard(tr + s, tc + s, dr, dc, s);
    else
    {
        board[tr + s][tc + s] = t1;
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}
//最近对问题
struct Point
{
    int x, y;
};
double ClosestPoints(Point S[], int low, int hight)
{
    double d1, d2, d3, d;
    Point P[n];
    if (hight - low == 1)
        return Distance(S[low], S[hight]);
    if (hight - low == 2)
    {
        d1 = Distance(S[low], S[low + 1]);
        d2 = Distance(S[low + 1], S[hight]);
        d3 = Distance(S[low], S[hight]);
        if ((d1 < d2) && (d1 < d3))
            return d1;
        else if (d2 < d3)
            return d2;
        else
            return d3;
    }
    int mid = (low + hight) / 2;
    d1 = ClosestPoints(S, low, mid);
    d2 = ClosestPoints(S, mid + 1, hight);
    if (d1 <= d2)
        d = d1;
    else
        d = d2;
    int index = 0;
    for (int i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--)
        P[index++] = S[i];
    for (int i = mid + 1; i < hight && S[i].x - S[mid].x < d; i++)
        P[index++] = S[i];
    QuickSort(P, 0, index - 1);
    for (int i = 0; i < index; i++)
        for (int j = i + 1; j < index; j++)
        {
            if (P[j].y - P[i].x >= d)
                break;
            else
            {
                d3 = Distance(P[i], P[j]);
                if (d3 < d)
                    d = d3;
            }
        }
    return d;
}
double Distance(Point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
