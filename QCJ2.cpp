#include<bits/stdc++.h>
using namespace std;

int n;

int solve(int idx,int k)
{
    if(k>idx)
        return 0;

    if(idx==1)
    {
        return 1;
    }

    int i,j;

    int ans=0;

    for(i=k;i>=0;i--)
        ans = ans + solve(idx-1,k-i);

    return ans;
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    while(n!=0)
    {
        int ans=solve(n,n);

        printf("%d\n",ans);

        scanf("%d",&n);
    }

    return 0;
}
