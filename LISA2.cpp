
#include<bits/stdc++.h>
using namespace std;

char str[110];

int n;

pair<int,int>memo[110][110];

pair<int,int> solve(int l,int r)
{
    int i,j;

    cout<<l<<" "<<r<<endl;

	if(l>r){
        cout<<"here1"<<endl;
		return (make_pair(0,0));
	}

	if(l==r)
	{
	    cout<<"here2"<<endl;
		return make_pair(str[l]-'0',str[l]-'0');
}

//if(memo[l][r].first!=-1)
	//return memo[l][r];



	int mn=INT_MAX;
	int mx=INT_MIN;

	int temp1=0,temp2=0;

	for(i=l+1;i<r;i+=2)
	{
		if(str[i]=='+')
		{
		    cout<<str[i]<<endl;
			temp1=solve(l,i-1).first + solve(i+1,r).first;
			temp2=solve(l,i-1).second + solve(i+1,r).second;
        }
        else if(str[i]=='*')
        {
            cout<<str[i]<<endl;
            temp1=solve(l,i-1).first * solve(i+1,r).first;
                    temp2=solve(l,i-1).second * solve(i+1,r).second;
        }

mx=max(mx,temp1);
mn=min(mn,temp2);
}

return memo[i][j]=make_pair(mx,mn);
}

int main()
{
	int test,t,i,j,k;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		//scanf("%d",&n);

		scanf("%s",str);

		n=strlen(str);

		cout<<str<<endl;
		cout<<n<<endl;

		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++){
				memo[i][j].first=-1;
				memo[i][j].second=-1;
}

pair<int,int> ans=solve(0,n-1);

printf("%d %d\n",ans.first,ans.second);
}

	return 0;
}


