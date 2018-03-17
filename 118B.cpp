#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k;
	int n;

	cin>>n;

	for(i=1;i<=2*n+1;i++)
	{
		if(i<=n)
		{
			for(j=1;j<=n-i+1;j++)
				cout<<"  ";

			for(j=0;j<i-1;j++)
				cout<<j<<" ";
			for(j=i-1;j>=0;j--){
                if(j>=1)
				cout<<j<<" ";
				else
                    cout<<j;
			}
}
else
{
	for(j=1;j<=i-n-1;j++)
		cout<<"  ";
	for(j=0;j<2*n+1-i;j++)
		cout<<j<<" ";
	for(j=2*n-i+1;j>=0;j--){
        if(j>=1)
		cout<<j<<" ";
		else
            cout<<j;
	}
}
if(i!=2*n+1)
cout<<endl;
}

	return 0;
}
