#include<bits/stdc++.h>
using namespace std;

int n;

char str[210];

int arr[210];

int getsum(int l,int r)
{
    return arr[r] - arr[l] + (str[l]-'0');
}

int memo[210][210];

int solve(int l,int r)
{
    int i,j,k;

    if(l==r)
        return getsum(l,l);

    if(getsum(l,r)>(r-l+1)/2)
        return (r-l+1);

    if(memo[l][r]!=-1)
        return memo[l][r];

    int ans=INT_MIN;

    for(i=l;i<r;i++)
    {
        ans=max(ans,solve(l,i) + solve(i+1,r));
    }

    return memo[l][r]=ans;
}

int main()
{
    int test,t,i,j,k;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                memo[i][j]=-1;

        scanf("%s",str);

        if(str[0]=='0')
            arr[0]=0;
        else
            arr[0]=1;

        for(i=1;i<n;i++)
        {
            if(str[i]=='0')
                arr[i]=arr[i-1];
            else
                arr[i]=arr[i-1] + 1;
        }

        int ans=solve(0,n-1);

        printf("%d\n",ans);
    }

    return 0;
}
