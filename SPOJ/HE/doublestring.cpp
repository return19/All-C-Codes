#include<iostream>
using namespace std;
int main()
{
 long long int a[10000],t,i;
 cin>>t;
 for(i=0;i<t;i++)
 {
 	cin>>a[i];
 }
 for(i=0;i<t;i++)
 {
 	if(a[i]%2!=0)
 	{
 		a[i]--;

 	}
 	cout<<a[i]<<endl;
 }
 return 0;
}
