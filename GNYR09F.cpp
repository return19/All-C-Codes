#include<bits/stdc++.h>
using namespace std;

int dp1[110];

int o[110];
int z[110];

void pre()
{
    int i,j,k;

    o[0]=o[1]=1;
    z[0]=z[1]=1;

    dp1[0]=1;
    dp1[1]=2;

    for(i=2;i<105;i++)
    {
        z[i]=o[i-1]+z[i-1];
        o[i]=z[i-1];
        dp1[i]=z[i]+o[i];
    }

   /* for(i=0;i<10;i++)
        cout<<dp1[i]<<" ";*/
}

map< pair<int,int>,int> memo;

int solve(int n,int x,int k)
{
    if(x>k||n<0)
        return 0;

    if(n<=1&&x!=k)
        return 0;

    if(x==k)
    {
        if(n==0)
        return 1;
            return dp1[n-1];
    }

    if(n<=k-x)
        return 0;

    int i,j;

    if(memo.find(make_pair(n,k-x))!=memo.end())
        return memo[make_pair(n,k-x)];

    int sum=solve(n-1,x,k);

    for(i=0;i<=k-x;i++)
    {
        if(i==0)
        {
            sum += solve(n-i-2,x+i,k);
        }
        else if(i==k-x)
        {
            sum += solve(n-i-1,x+i,k);
        }
        else
            sum += solve(n-i-2,x+i,k);
    }

    //cout<<n<<" "<<k-x<<" "<<sum<<endl;

    return memo[make_pair(n,k-x)]=sum;
}

int main()
{
    int test,i,j,t;
    int n,k;
    int ans;

    pre();

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d%d",&i,&n,&k);

        ans=solve(n,0,k);

        printf("%d %d\n",t+1,ans);
    }

    return 0;
}
