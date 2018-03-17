#include<bits/stdc++.h>
using namespace std;

int arr[110];

int n;

int memo[110][5][5];
int base[110][5][5];

int solve(int idx,int d,int k)
{
    if(idx==n)
    {
        return 0;
    }

    if(base[idx][d][k]==1)
        return memo[idx][d][k];

    base[idx][d][k]=1;

    int tk,nt;
    int i,j;

    i=idx;

    while(i<n && arr[i]!=d)
        i++;

    if(i==n)
        nt=0;
    else
        nt=1 + solve(i+1,d,k);

    if(k==0)
        return memo[idx][d][k]=nt;

    i=idx;

    while(i<n && arr[i]==(1-d))
        i++;

    if(i==n)
        return memo[idx][d][k]=nt;

    tk=1 + solve(i+1,1-d,k-1);

    return memo[idx][d][k]=max(nt,tk);

}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int ans=max(solve(0,1,2),solve(0,0,1));

    int c=0;

    for(i=0;i<n;i++)
    {
        if(arr[i])
            c++;
    }

    if(c==n)
        ans=n-1;

    printf("%d\n",ans);

    return 0;
}
