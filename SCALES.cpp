#include<bits/stdc++.h>
using namespace std;

long long n,l,d;

char arr[10010000];
long long memo[2001000][2];
/*
long long solve(long long idx,long long c)
{
    if(idx==n)
    {
        if(c==0)
            return 1;
        return 0;
    }

    if(memo[idx][c]!=-1)
        return memo[idx][c];

    if(idx>=l || arr[idx]=='0')
    {
        if(c==0)
        {
            return memo[idx][c]=solve(idx+1,0);
        }
        else // c==1
        {
            return memo[idx][c]=(solve(idx+1,0) + solve(idx+1,1))%d;
        }
    }else // arr[idx] =='1'
    {
        if(c==1)
            return memo[idx][c]=solve(idx+1,1);
        return memo[idx][c]=(solve(idx+1,0) + solve(idx+1,1))%d;
    }
}*/

int solve(int idx,int c)
{
    return memo[idx][c];
}

int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld",&n,&l,&d);
        scanf("%s",arr);
        for(i=0,j=l-1;i<j;i++,j--)
        {
            swap(arr[i],arr[j]);
        }

        /*for(i=0;i<=1000010;i++)
            for(j=0;j<2;j++)
                memo[i][j]=-1;*/

        memo[n][0]=1;
        memo[n][1]=0;

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int c=0;c<2;c++)
            {
                if(idx>=l || arr[idx]=='0')
                {
                    if(c==0)
                    {
                         memo[idx][c]=solve(idx+1,0);
                    }
                    else // c==1
                    {
                         memo[idx][c]=(solve(idx+1,0) + solve(idx+1,1))%d;
                    }
                }else // arr[idx] =='1'
                {
                    if(c==1)
                         memo[idx][c]=solve(idx+1,1);
                    else
                        memo[idx][c]=(solve(idx+1,0) + solve(idx+1,1))%d;
                }
            }
        }

        long long ans=solve(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}












