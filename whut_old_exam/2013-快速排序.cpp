#include <cstdio>
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) //从右到左找到第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] <= x) //从左往右找到第一个大于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }

        s[i] = x;                //i = j的时候，将x填入中间位置
        quick_sort(s, l, i - 1); //递归调用
        quick_sort(s, i + 1, r);
    }
}

int main()
{

    return 0;
}