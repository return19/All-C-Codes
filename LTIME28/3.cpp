#include<bits/stdc++.h>
using namespace std;
//coffee

int arr[101000];

int n,k,d,m;

map< pair<pair<int,int>,int>,int > memo;

int solve(int x,int y,int last)
{
    int i,j;

    if(x==n)
    {
        if(y==k)
            return 0;

        return INT_MIN;
    }


    if(memo.find(make_pair(make_pair(x,y),last))!=memo.end())
        return memo[make_pair(make_pair(x,y),last)];

    int ans=0;

    if(y==k)
    {
        if(last!=-1&&x-last<=d)
        {
            return memo[make_pair(make_pair(x,y),last)]=arr[x]*m + solve(x+1,y,last);
        }
        else
            return memo[make_pair(make_pair(x,y),last)]=arr[x] + solve(x+1,y,last);
    }
    else
    {
        int t,nt;

        t= solve(x+1,y+1,x);

        if(last!=-1&&x-last<=d)
        {
            nt= arr[x]*m + solve(x+1,y,last);
        }
        else
            nt = arr[x] + solve(x+1,y,last);

        return memo[make_pair(make_pair(x,y),last)]=max(t,nt);
    }

}

int main()
{
    int i,j;
    int t,test;

    int ans;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();

        scanf("%d%d%d%d",&n,&k,&d,&m);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        ans=solve(0,0,-1);

        printf("%d\n",ans);
    }

    return 0;
}
