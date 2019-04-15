#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#define N 10
#define range 100 

using namespace std;

struct pairs
{
	int a;
	int b;
};

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	srand((unsigned) time(NULL)); //时间数种子，每次产生的随机数不同
	//int a[N];
	//int b[N];
	//int *a = (int *)malloc(N*sizeof(int));
	//int *b = (int *)malloc(N*sizeof(int));
	int *a = new int[N];
	int *b = new int[N];
	std::vector<struct pairs> c;
	struct pairs tmp;
	int abMax = 0;
	for (int i=0; i<N; i++)
	{
		a[i] = rand()%range;
		b[i] = rand()%range;
	}
	for (int i=0; i<N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i=0; i<N; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	sort(a,a+N);
	sort(b,b+N,cmp);
	for (int i=0; i<N; i++)
	{
		tmp.a = a[i];
		tmp.b = b[i];
		abMax += abs(a[i]-b[i]);
		c.push_back(tmp);
	}
	printf("absolute sum max: %d\n", abMax);
	//free(a);
	//free(b);
	delete []a;
	delete []b;
	return 0;
}


