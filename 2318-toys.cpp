#include<stdio.h>

struct Node
{
	int x1, x2, y1, y2;
}p[5555];

bool is_in(int x, int y, int a)
{
	int x1 = p[a].x1;
	int x2 = p[a].x2;
	int y1 = p[a].y1;
	int y2 = p[a].y2;
	int ans=((x1-x)*(y2-y)-(y1-y)*(x2-x)); //Ð±ÂÊ±È½Ï 
    return ans>0?true:false;
}

int main()
{
	int n, m, xl, yl, xr, yr;
	while (scanf("%d", &n))
	{
		if (n != 0)
		{
			scanf("%d%d%d%d%d", &m, &xl, &yl, &xr, &yr);
			for (int i=1; i<=n; i++)
			{
				scanf("%d%d", &p[i].x1, &p[i].x2);
				p[i].y1 = yl;
				p[i].y2 = yr;
			}
			p[0].x1 = xl;
			p[0].x2 = xl;
			p[n+1].x1 = xr;
			p[n+1].x2 = xr;
			for (int i=0; i<=n+1; i++)
			{
				p[i].y1 = yl;
				p[i].y2 = yr;
			}
			int cnt[5555] = {0};
			int x, y;
			while (m--)
			{
				scanf("%d%d", &x, &y);
				int tmp = 0;
				while (is_in(x, y, tmp++));
				tmp = tmp - 2;
				cnt[tmp]++;
			}
			
			for (int i=0; i<=n; i++)
				printf("%d: %d\n", i, cnt[i]);
			printf("\n");
		}
		else
			break;
	}
}
