#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10010

using namespace std;

int a[N];
int n;

int partition(int left, int right)
{
	int i,j,tmp,t;
	
	tmp = a[left];
	i = left;
	j = right;
	while (i!=j)
	{
		//ÏÈ´ÓÓÒµ½××ó
		while (a[j] >= tmp && i<j)
			j--;
		while (a[i] <= tmp && i<j)
			i++;
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		} 
	}
	a[left] = a[i];
	a[i] = tmp;
	return i;
}

void Quick(int left, int right)
{
	if (left>right)
		return;
	
	int pivot = partition(left, right);
	Quick(left, pivot-1);
	Quick(pivot+1, right);
}

int main()
{
	int mid;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	Quick(0,n-1);
	for (int i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	mid = a[n/2];
	printf("%d\n",mid);
	return 0;
}
