#include<iostream>
using namespace std;

int main()
{
	long long int a[1001];
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a[i];
		a[i]=a[i]/2+1;

	}
	for(i=0;i<t;i++)
	cout<<a[i]<<endl;

	return 0;

}
