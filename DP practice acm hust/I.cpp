#include<bits/stdc++.h>
using namespace std;

int arr[210];
int csum[210];
int memo[210][210];

int sum(int l,int r)
{
    if(l==0)    return csum[r];
    return csum[r]-csum[l-1];
}

int solve(int l,int r)
{
    int i,j,k;
    if(l==r)
        return arr[l];

    if(sum(l,r)>(r-l+1)/2)
        return (r-l+1);

    if(memo[l][r]!=-1)
        return memo[l][r];

    int ans=0;

    for(i=l;i<r;i++)
    {
        ans=max(ans,solve(l,i)+solve(i+1,r));
    }
    return memo[l][r]=ans;
}

int main()
{
    int i,j,k;
    int test,t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%1d",&arr[i]);

        csum[0]=arr[0];
        for(i=1;i<n;i++)
            csum[i]= csum[i-1] + arr[i];

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                memo[i][j]=-1;

        int ans=solve(0,n-1);
        printf("%d\n",ans);
    }
    return 0;
}
