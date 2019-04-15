#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
 
using namespace std;

char seq[125];
int marked[125];
int q[125];
int w[125];

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		memset(seq, 0, sizeof(seq));
		memset(marked, 0, sizeof(marked));
		memset(q, 0, sizeof(q));
		memset(w, 0, sizeof(w));
		int top = -1;
		int topw = -1;
		cin >> n;
		for (int i=0; i<n; i++)
			scanf("%d", &q[i]);
		for (int i=0; i<q[0]; i++)
		{
			seq[++top] = '(';
		}
		seq[++top] = ')';
		for (int i=1; i<n; i++)
		{
			for (int j=0; j<(q[i]-q[i-1]); j++)
			{
				seq[++top] = '(';
			}
			seq[++top] = ')';
		}
		
		for (int i=0; i<=top; i++)
		{
			if (seq[i] == ')')
			{
				for (int j=i-1; j>=0; j--)
				{
					if (marked[j] == 0 && seq[j] == '(')
					{
						marked[j] = 1;
						w[++topw] = (i-j+1)/2;
						break;
					}
				}
			}
		}
		
		for (int i=0; i<=topw; i++)
		{
			printf("%d ", w[i]);
		}
		printf("\n");
	}
	
	return 0;
} 
