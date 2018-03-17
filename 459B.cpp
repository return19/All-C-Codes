#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long i,j,k;
long long n;
long long mx=LLONG_MIN,mn=LLONG_MAX;
long long mn_c=0,mx_c=0;

long long temp;

cin>>n;

for(i=0;i<n;i++)
{
	cin>>temp;

	if(temp>mx)
	{
		mx=temp;
		mx_c=1;
}
else if(temp==mx)
{
	mx_c++;
}

if(temp<mn)
{
mn=temp;
mn_c=1;
}
else if(temp==mn)
{
	mn_c++;
}
}

if(mn==mx)
{
	cout<<0<<" "<<mn_c*(mn_c-1)/2<<endl;
}
else
{
	cout<<mx-mn<<" "<<mx_c*mn_c<<endl;
}



	return 0;
}

