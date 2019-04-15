#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[21][15010];
int p[21], w[21];

int main()
{
	int c, g;
	scanf("%d %d", &c, &g);
	for (int i=1; i<=c; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i=1; i<=g; i++)
	{
		scanf("%d", &w[i]);
	}
	
	memset(dp, 0, sizeof(dp));
	dp[0][7500] = 1;
	for (int i=1; i<=g; i++)
	{
		for (int j=0; j<=15000; j++)
		{
			if (dp[i-1][j])
			{
				for (int k=1; k<=c; k++)
					dp[i][j+p[k]*w[i]] += dp[i-1][j];
			}
		}
	}
	printf("%d\n", dp[g][7500]);
	return 0;
}
