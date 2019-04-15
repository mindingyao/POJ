#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define N 30
 
using namespace std;

int n, m, in[N];
char ans[N], q[N];
vector<int> e[N];

int topo_sort()
{
	int d[N], ret = 1;
    memcpy(d, in, sizeof(d));
    int front  = 0, rear = 0, p = 0;
    for(int i = 0; i < n; ++i)
        if(d[i] == 0) q[rear++] = i;
    while(front < rear)
    {
        if(rear - front > 1) ret = 0; //˳����ȷ��
        int cur = q[front++];
        ans[p++] = 'A' + cur;
        for(int i = 0; i < e[cur].size(); ++i)
        {
            int j = e[cur][i];
            if((--d[j]) == 0) q[rear++] = j;
        }
    }
    if(p < n) return -1; //�л�
    ans[p] = 0;
    return ret;
}
int main()
{
	char a, b;
    while(scanf("%d%d", &n, &m), n || m)
    {
        for(int i = 0; i < n; ++i) e[i].clear();
        memset(in, 0, sizeof(in));
        int flag = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf(" %c<%c", &a, &b);
            if(flag) continue;
 
            a -= 'A', b -= 'A';
            e[a].push_back(b);
            ++in[b];
            flag = topo_sort();
            if(flag == 1)
                printf("Sorted sequence determined after %d relations: %s.\n", i + 1, ans);
            if(flag == -1)
                printf("Inconsistency found after %d relations.\n", i + 1);
 
        }
        if(!flag) puts("Sorted sequence cannot be determined.");
    }
    return 0;	
}


