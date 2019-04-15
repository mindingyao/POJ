#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[1000010];
int b[11]={1,2,4,8,16,32,64,128,256,512,1024};
int n[230], w[230];
int ans,N;

int main()
{
	while (scanf("%d%d", &ans, &N) != EOF)
	{
		memset(n, 0, sizeof(n));
		memset(w, 0, sizeof(w));
		memset(dp, 0, sizeof(dp));
		int count = 1;
		for (int i=0; i<N; i++)
		{
			int nn, ww, j, k;
			scanf("%d%d", &nn, &ww);
			if (nn != 0)
			{
				for (j=10; j>=0; j--)
					if (nn-b[j]+1>0)
						break;
				
				for (k=0; k<j; k++)
				{
					n[count] = b[k];
					w[count] = ww*b[k];
					count++;
				}
				n[count] = nn-b[j]+1;
				w[count] = ww*(nn-b[j]+1);
				count++;
			}
		}
		count--;
		for (int i=1; i<=count; i++)
		{
			for (int j=ans; j>=w[i]; j--)
			{
				dp[j] = max(dp[j], dp[j-w[i]]+w[i]);
			}
		}
		
		printf("%d\n", dp[ans]);
	}
	
	return 0;
} 
