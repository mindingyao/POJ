#include<iostream>
using namespace std;

int main()
{
	int T, x;
	cin>>T;
	
	for (int i=0; i<T; i++)
	{
		cin>>x;
		int min = x-(x&(-x))+1;
		int max = x+(x&(-x))-1;
		cout<<min<<" "<<max<<endl;
	}
	
	return 0;
} 
