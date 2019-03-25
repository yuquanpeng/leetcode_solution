#include<cstdio> 
#include <cstring>
using namespace std;

int maxsub(int a[],int n)    
{
    int i,max=0,b=0;
    for(i=0;i<n;i++)
    {
        if(b > 0)
            b += a[i];
        else 
            b = a[i];
        if(b > max)
            max = b;
    }
    return max;
}

int main()
{
	FILE *in,*out;
	if((in = fopen("2014-最大子矩阵-input.txt","r")) == NULL)
		printf("file open fail\n");
	if((out = fopen("2014-最大子矩阵-output.txt","w")) == NULL)
		printf("file open fail\n");
    int n,maxsubrec,maxsubarr;
    int dp[101][101],arr[101];
    
    while(!feof(in))
    {
    	fscanf(in,"%d",&n);
    	while(n!=0)
    	{
	    	for(int i=0;i<n;i++)
	             for(int j=0;j<n;j++)
					fscanf(in,"%d",&dp[i][j]);
	                 
	         maxsubrec = 0;
	         for(int i=0;i<n;i++)
	         {
	             memset(arr,0,sizeof(arr));
	             for(int j=i;j<n;j++)
	             {
	                 for(int k=0;k<n;k++)
	                     arr[k] += dp[j][k];
	                 maxsubarr = maxsub(arr,n);
	                 if(maxsubarr > maxsubrec) 
					 	maxsubrec = maxsubarr;
	             }
	         }
	         fprintf(out,"%d",maxsubrec);
	         fscanf(in,"%d",&n);
		}
	}

    fclose(in);
    fclose(out);
    return 0;
}
