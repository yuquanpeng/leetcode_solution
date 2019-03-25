//模式匹配BF算法
int BF(char s[], char t[])
{
    int index = 0;    //主串开始的下标
    int i = 0, j = 0; //比较的起始下标
    while (s[i] != '\0' && t[i] != '\0')
    {
        if (s[i] == t[i])
        {
            i++;
            j++;
        }
        else
        {
            index++;
            i = index;
            j = 0;
        }
    }
}
//模式匹配KMP
void getNext(chat T[], int next[])
{
    int i, j, len;
    next[0] = -1;
    for (int j = 1; next[j] != '\0'; j++)
    {
        for (int len = j - 1; len >= 1; len--) //相等子串的最大长度为j-1
        {
            for (int i = 0; i < len; i++) //依次比较
                if (T[i] != T[j - len + i])
                    break;
            if (i == len)
                next[j] = len;
            break;
        }
        if (len < 1) //其他情况 没有相等子串
            next[j] = 0;
    }
}
int KMP(char S[], char T[])
{
    int i = 0, j = 0;
    int next[80];
    getNext(t, next);
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
    if (T == '\0')
        return (i - strlen(T) + 1);
    else
        return 0;
}
//选择排序
//在无序区查找最小值 与 当前无序区的首位交换 无序区逐渐缩小 有序区逐渐扩大
void selectSort(int r[], int n)
{
    int index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;                      //初始化最小值
        for (int j = i + 1; j < n; j++) //寻找下一个最小值
            if (r[j] < r[index])
                index = j;
        if (index != i) //不重复 则交换
        {
            temp = r[i];
            r[i] = r[index];
            r[index] = temp;
        }
    }
}
//冒泡排序
void bubbleSort(int r[], int n)
{
    int bound, exchange = n - 1;
    while (exchange != 0)
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)
        {
            if (r[j] > r[j + 1])
            {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                exchange = j;
            }
        }
    }
}
//01背包问题
//任务非配问题
//哈密顿回路问题
//TSP问题
//最近对问题
//凸包问题