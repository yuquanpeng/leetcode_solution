#include <stdio.h>
#include <algorithm>
using namespace std;
struct Program
{
    int startTime;
    int endTime;
    bool operator<(const Program &A)
    {
        return endTime < A.endTime;
    }
} buf[100];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
        }
        sort(buf, buf + n);
        int currentTime = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (currentTime <= buf[i].startTime)
            {
                currentTime = buf[i].endTime;
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}