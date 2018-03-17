#include<bits/stdc++.h>
using namespace std;

int n;
int arr[510];

int memo[510][65010];

int solve(int idx,int sum)
{
    if(idx>n)
        return sum;

    if(memo[idx][sum]!=-1)
        return memo[idx][sum];
    int po,ne;

    po = solve(idx+2,abs(sum + arr[idx]));
    ne = solve(idx+2,abs(sum - arr[idx]));

    return memo[idx][sum]=min(po,ne);
}

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        string s;
        scanf("%d",&arr[0]);

        for(i=1;i<=n;i++)
        {
            cin>>s;
            scanf("%d",&arr[i]);
        }

        for(i=2;i<=n;i+=2)
            for(j=0;j<65010;j++)
                memo[i][j]=-1;

        int ft=solve(2,arr[0]);

         for(i=1;i<=n;i+=2)
            for(j=0;j<65010;j++)
                memo[i][j]=-1;

        int sd=solve(1,0);

        printf("%d\n",ft+sd);
    }
    return 0;
}











