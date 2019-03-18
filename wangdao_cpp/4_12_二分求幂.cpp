#include <stdio.h>
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        int ans = 1;
        while (b != 0) //若b不为0 对b转换二进制过程未结束
        {
            if (b % 2 == 1)
            {
                ans *= a;
                ans %= 1000;
            }
            b /= 2;
            a *= a;
            a %= 1000;
        }
        printf("%d\n", ans);
    }

    return 0;
}