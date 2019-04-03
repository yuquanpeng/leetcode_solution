#include <cstdio>
#define MAXM 100
#define MAXN 100
int map[MAXM][MAXN] = {-1};
int main()
{
	FILE *fp_in, *fp_out;
	int m, n;
	if ((fp_in = fopen("2012-二维数组马鞍点-input.txt", "r")) == NULL)
		printf("file open fail\n");
	if ((fp_out = fopen("2012-二维数组马鞍点-output.txt", "w")) == NULL)
		printf("file open fail\n");

	int count = 0;

	while (!feof(fp_in))
	{
		fscanf(fp_in, "%d", &m);
		fscanf(fp_in, "%d", &n);
		while (m != 0 && n != 0)
		{
			//			printf("%d---%d\n",m,n);
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
					fscanf(fp_in, "%d", &map[i][j]);

			int f = 1, p;
			for (int i = 1; i <= m; i++) //每一行上的元素
			{
				for (int j = 1; j <= n; j++)
				{
					if (map[i][f] < map[i][j])
						f = j; //找出每一行元素的最小值
				}
				for (p = 1; p <= m; p++) //循环判断每一行元素的最小值是否是它所在列的最大值
					if (map[i][f] > map[p][f])
						break;

				f = 1;
			}
			if (p == m + 1)
				fprintf(fp_out, "%d %d", 0, 0);
			else
				//				printf("%d %d\n",p,f);//如果是则输出 每个一行 否则会出现格式错误
				fprintf(fp_out, "%d %d\n", p, f);
			fscanf(fp_in, "%d", &m);
			fscanf(fp_in, "%d", &n);
		}
	}

	if (fclose(fp_in) != 0 || fclose(fp_out) != 0)
		printf("file close fail\n");
	return 0;
}