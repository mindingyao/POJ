#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>


#define maxn 1005
 
long long dp[10][9*maxn]; //用dp[i][j]表示i个数的和为j的总数 有dp[i][j]=dp[i-1][j-k](k从0到9)。
int n;

int main()
{
	long long ans;
	scanf("%d", &n);
	n = n/2;
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<=9; i++)
	{
		dp[1][i] = 1;
	}
	
	for (int i=2; i<=n; i++)
	{
		for (int k=0; k<=n*9; k++)
		{
			long long sum=0;
			for(int j=0;j<=9;j++)
			{
				if(k>=j)
					sum = (sum+dp[(i-1)][k-j]);
				else
					dp[i][k]=0;
			}
			dp[i][k]=sum;
		}
	}
	
	ans = 0;
	for (int i=0; i<=n*9; i++)
	{
		ans += dp[n][i]*(dp[n][i]);
	}
	
	printf("%d\n", ans);
	return 0;
	
	
}
/*

#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;
 
#define maxn 1005
const int mod = 1000000007;
 
long long dp[2][9*maxn];
int n;
 
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
 
	int i,j,k;
	long long ans;
	cin>>n;
	n=n/2;
	memset(dp,0,sizeof(dp)); 
	//dp[0][1]=1;//此处单独为了1 考虑 //不考虑第一个为0的情况 
	for(i = 0; i <= 9; ++ i)  
	{  
		dp[1][i] = 1;  
	} 
	for(i=2;i<=n;i++)
	{
		for(k=0;k<=n*9;k++)
		{
			long long sum=0;
			for(j=0;j<=9;j++)
			{
				if(k>=j)
					sum = (sum+dp[(i-1)&1][k-j])%mod;
				else
					dp[i&1][k]=0;
			}
			dp[i&1][k]=sum;
		}
	}
	ans=0;
	for(i=0;i<=n*9;i++)
	{
		ans = (ans+dp[n&1][i]*(dp[n&1][i]))%mod;
	}
 
	cout<<ans<<endl;
	
	//system("pause");
	return 0;
}
*/
