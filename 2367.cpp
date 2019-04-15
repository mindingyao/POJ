#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

#define N 105

int A[N][N];
int marked[N];
int list[N]; //输出序列 
int cont[N]; //节点入度 

int n;
int res[N];
int s = 0;

void dfs(int i)
{
	marked[i] = 1;
	for (int j=1; j<=n; j++)
	{
		if (A[i][j] && !marked[j])
			dfs(j);
	}
	res[++s] = i;
}

void topo_sort()
{
	for (int i=1; i<=n; i++)
	{
		if (!marked[i])
			dfs(i);
	}
}


/*
void topo_sort()
{
	int k=0;
	while (k!=-1)
	{
		for (int i=1; i<=n; i++)
		{
			if (cont[i]==0 && !marked[i])
			{
				list[++k] = i;
				marked[i] = 1;
				for (int j=1; j<=n; j++)
				{
					if (A[i][j])
					{
						A[i][j] = 0;
						cont[j]--;
					}
				}
			}
		}
		
		if (k == n)
			break;
	}
}
*/

int main()
{
	int s;
	memset(marked, 0, sizeof(marked));
	memset(A, 0, sizeof(A));
	//memset(list, 0, sizeof(list));
	//memset(cont, 0, sizeof(cont));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &s);
		while (s != 0)
		{
			A[i][s] = 1;
			//cont[s]++;
			scanf("%d", &s);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	topo_sort();
	/*
	for (int i=1; i<=n; i++)
		printf("%d ", list[i]);*/
	for (int i=n; i>0; i--)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}


