#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int p[5000];
int maxn = 10000;

bool prime(int num)
{
	for (int i=2; i<=sqrt(num); i++)
	{
		if (num%i == 0)
			{
				return false;
				break;
			}
	}
	return true;
}


int cal(int a)
{
	int result = 0;
	for (int start = 0; start < 5000; start++)
	{
		int sum = p[start];
		if (sum == a)
			result++;
		for (int j = start+1; j < 5000; j++)
		{
			if ((sum + p[j] < a))
				sum += p[j];
			else if (sum + p[j] == a)
			{
				result++;
				break;
			}
			else
				break;
		}
	}
	
	return result;
} 

int main()
{
	int count, num;
	int index=0;
	for (int i=2; i<=maxn; i++)
	{
		if (prime(i))
			p[index++]=i;	
	}
	scanf("%d", &num);
	while (num != 0)
	{
		count = cal(num);
		printf("%d\n", count);
		scanf("%d", &num);
	}
	return 0;
}
