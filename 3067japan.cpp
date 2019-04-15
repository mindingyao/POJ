#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N (1005*1005)
 
using namespace std;


struct highway
{
	int w, e;
}p[N];

int c[N];
int n, m, k;

int lowbit(int x)
{
	return x & (-x);
}

int getSum(int i)
{
	int sum = 0;
	while (i > 0)
	{
		sum += c[i];
		i -= lowbit(i);
	}
	return sum;
}

void update(int i, int val)
{
	while (i <= m)
	{
		c[i] += val;
		i += lowbit(i);
	}
}

bool cmp(highway a, highway b)
{
	if (a.w != b.w)
		return a.w < b.w;
	return a.e < b.e;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		memset(c, 0, sizeof(c));
		for (int i=1; i<=k; i++)
			scanf("%d%d", &p[i].w, &p[i].e);
		sort(p+1, p+k+1, cmp);
		int res = 0;
		for (int i=1; i<=k; i++)
		{
			update(p[i].e,1);
			res += i - getSum(p[i].e);
		}
		
		printf("Test case %d: %d\n", t+1, res);
	}
	
	return 0;
}














/* violence algorithm 
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T, N, M, K;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d%d%d", &N, &M, &K);
		int* west = (int *)malloc(K*sizeof(int));
		int* east = (int *)malloc(K*sizeof(int));
		for (int i=0; i<K; i++)
		{
			scanf("%d%d", &west[i], &east[i]);
		}
		int cnt=0;
		for (int i=0; i<K-1;i++)
			for (int j=i+1;j<K;j++)
			{
				if ((west[i]-west[j])*(east[i]-east[j])<0)
					cnt++;
			}
		
		printf("Test case %d: %d", T, cnt);
		free(west);
		free(east);
	}
	return 0;
} */

