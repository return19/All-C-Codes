#include<bits/stdc++.h>
using namespace std;

char str[101000];

int arr[101000];

int n;

int memo[101000][4][4];
int base[101000][4][4];

int solve(int idx,int d,int k)
{
    int i,j;

    if(idx==n)
    {
        return 0;
    }

    if(base[idx][d][k]==1)
        return memo[idx][d][k];

    base[idx][d][k]=1;

    i=idx;

    while(i<n && arr[i]!=d)
        i++;

    int tk,nt;

    if(i==n)
        nt=0;
    else
        nt=1 + solve(i+1,1-d,k);

    i=idx;

    if(k==0)
        return memo[idx][d][k]=nt;

    while(i<n && arr[i]!=(1-d))
        i++;

    if(i==n)
        return memo[idx][d][k]=nt;

    tk=1 + solve(i+1,d,k-1);

    return memo[idx][d][k]=max(tk,nt);

}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    scanf("%s",str);

    for(i=0;i<n;i++)
        arr[i]=str[i]-'0';

    int ans=max(solve(0,1-arr[0],1) , solve(0,arr[0],2));

    printf("%d\n",ans);

    return 0;
}
