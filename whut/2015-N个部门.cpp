#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 101
int min = 123123123;
int distribut(int a[][], int n, int sum)
{
    if (n == 1)
    {
        min = min(sum + s[0][1], min);
        return min;
    }
}

int main()
{
    FILE *in, *out;
    if ((in = fopen("2015-N个部门-input.txt", "r")) == NULL)
        printf("file open fail\n");
    if ((out = fopen("2015-N个部门-output.txt", "w")) == NULL)
        printf("file open fail\n");

    int n;
    int N[MAX][2] = {-1};
    while (!feof(in))
    {
        fscanf(in, "%d", &n);
        while (n != 0)
        {
            for (int i = 0; i < n; i++)
                fscanf(in, "%d %d", &N[i][0], &N[i][1]);

            fscanf(in, "%d", &n);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}