#include<bits/stdc++.h>
using namespace std;

/*
int solve(int n)
{
    if(n==1)    return 1;
    return (solve(n-1) + 1)%n + 1;
}*/

//int dp[100100000];

int main()
{
    long long i,j,k;
    long long x,y,z;
    long long n;
    char str[10];

    scanf("%s",str);
    x=str[0]-'0';
    y=str[1]-'0';
    z=str[3]-'0';

    while(!(x==0 && y==0 && z==0))
    {
        n = (x*10 + y)*pow(10,z);

        /*for(i=1;i<=n;i++)
        {
            if(i==1){
                dp[i]=1;
                continue;
            }
            dp[i]=(dp[i-1] + 1)%i + 1;
        }

        printf("%d\n",dp[n]);*/

        long long t=n;
        long long c=-1;
        while(t!=0)
        {
            c++;
            t=t>>1;
        }

        long long ans=n-(1<<c);
        ans=ans*2 + 1;

        printf("%lld\n",ans);

        scanf("%s",str);
        x=str[0]-'0';
        y=str[1]-'0';
        z=str[3]-'0';
    }
    return 0;
}
