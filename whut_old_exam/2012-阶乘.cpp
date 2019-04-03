#include<cstdio>
long long cal(int n)
{
	int t=1,ans;
	for (int i=1;i<=n;i++){
        t=t*i;
        ans+=t;
    }
    return ans;
}
int main()
{
	int n;
	long long res = -1;
	while(scanf("%d",&n)!=EOF)
	{
		res = cal(n);
		printf("%lld\n",res);
	}
 } 


