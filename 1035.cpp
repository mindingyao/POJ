#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 10010

using namespace std;

char dic[maxn][20];
char str[20];

int check(int n)
{
	int i, j;
	int cnt; //the number of different letters
	int len1 = strlen(str);
	int len2 = strlen(dic[n]);
	if (len1 == len2)
	{
		cnt=0;
        i=j=0;
        for(; i<len1;) {
            if(str[i]!=dic[n][j])
                cnt++;
            i++,j++;
        }
        if(cnt==1)
            return 1;
        return 0;
	}
	else if (len1+1 == len2)
	{
		cnt = 0;
		for (i = 0, j=0; i<len1 || j<len2;)
		{
			if (str[i] == dic[n][j])
			{
				i++;j++;
			}
			else
			{
				j++;
				cnt++;
			}
		}
		if (cnt==1)
			return 1;
		return 0;
	}
	else if(len1-1==len2)
	{
		cnt = 0;
		for (i = 0, j=0; i<len1 || j<len2;)
		{
			if (str[i] == dic[n][j])
			{
				i++;j++;
			}
			else
			{
				i++;
				cnt++;
			}
		}
		if (cnt==1)
			return 1;
		return 0;
	}
	
	return 0;
}

int main()
{
	int i, n=0;
	while (~scanf("%s", dic[n]))
	{
		if (dic[n][0] == '#')
			break;
		n++;
	}
	while (~scanf("%s", str))
	{
		if (str[0] == '#')
			break;
		for (i = 0; i<n; i++)
		{
			if (strcmp(str,dic[i])==0)
			{
				printf("%s is correct\n", str);
				break;
			}
		}
		if (i==n)
		{
			printf("%s: ", str);
			for (i = 0; i<n; i++)
			{
				if (check(i))
				{
					printf("%s ", dic[i]);
				}
			}
			printf("\n");
		}
			
	}
	
	return 0;
}
