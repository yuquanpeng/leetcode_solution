#include<cstdio>
int cal(int m,int n)
{
	if(n==1) return m;
	else 
	return cal(m,n-1)*m;
 } 
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",cal(m,n));
	}
	return 0;
}
