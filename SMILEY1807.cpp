#include<bits/stdc++.h>
using namespace std;


char arr[1010000];

int n;

char seq[11]={'a','1','8','0','7','a'};

int memo[1010000][11];
int base[1010000][11];

int solve(int idx,int x)
{
    if(x==5)
        return 0;

    if(idx==n)
    {
        if(x>=4)
            return 0;
        return INT_MIN;
    }

    if(base[idx][x]==1)
        return memo[idx][x];

    base[idx][x]=1;

    if(arr[idx]==seq[x])
    {
        return memo[idx][x]=1+solve(idx+1,x);
    }
    else if(arr[idx]==seq[x+1])
    {
       // cout<<idx<<" "<<x<<" "<<1+solve(idx+1,x+1)<<endl;
        return memo[idx][x]=max(solve(idx+1,x),1+solve(idx+1,x+1));
    }



    return memo[idx][x]=solve(idx+1,x);
}

int main()
{
    int i,j,k;

    scanf("%s",arr);

    n=strlen(arr);

    int ans=solve(0,0);

    printf("%d\n",max(0,ans));

    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int n;

char str[1010000];

int arr[1010000];

int seq[11]={-1,1,8,0,7,-1,-1,-1};

map< pair<int,int>,int > memo;

int solve(int idx,int x)
{

	if(idx==n)
	{
		if(x>=4)
			return 0;
		return INT_MIN;
}

if(x==5)
    return 0;

if(memo.find(make_pair(idx,x))!=memo.end())
    return memo[make_pair(idx,x)];

int tk=0,nt=0;

int i,j;

if(arr[idx]==seq[x])
{
	tk= 1 + solve(idx+1,x);

	return memo[make_pair(idx,x)]=tk;
}
else if(arr[idx]==seq[x+1])
{
	tk= 1 + solve(idx+1,x+1);
	nt=solve(idx+1,x);

	return memo[make_pair(idx,x)]=max(tk,nt);
}
else
{
	return memo[make_pair(idx,x)]=solve(idx+1,x);
}


}

int main()
{
	int i,j,k;

	scanf("%s",str);

	n=strlen(str);

	for(i=0;i<n;i++)
		arr[i]=str[i]-'0';

	int ans=solve(0,0);

    if(ans>=0)
	printf("%d\n",ans);
    else
        printf("0\n");

	return 0;
}
*/
