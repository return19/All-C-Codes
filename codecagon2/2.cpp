#include<bits/stdc++.h>
using namespace std;

long long p[1010000];
long long arr[31];
long long n;

long long sv[1010000];
vector<long long> pm;

long long mx=LLONG_MIN;

void sieve()
{
    long long i,j,k;
    long long t;

    sv[0]=sv[1]=1;

    for(i=2;i<=1000010;i++)
    {
        if(sv[i]==0)
        {
            pm.push_back(i);

            k=i;
            t=2;
            for(j=t*k;j<=1000010;j=t*k)
            {
                sv[j]=1;
                t++;
            }
        }
    }
}

void pre()
{
    long long i,j,k;
    long long x,y;
    p[0]=p[1]=0;

    for(i=2;i<=mx;i++)
    {
        //cout<<i<<endl;
        p[i]=p[i-1];
        x=i;

        for(j=0;pm[j]*pm[j]<=i;j++)
        {
            while(x%pm[j]==0)
            {
                p[i]++;
                x/=pm[j];
            }
        }
        if(x>1)
            p[i]++;
    }

}

long long ans=0;

void solve(long long idx,long long sum)
{
    long long i,j,k;

    if(idx==n)
    {
        if(sum%2==0)
            ans+=sum;
        return;
    }

    solve(idx+1,sum);
    solve(idx+1,sum+p[arr[idx]]);

}

int main()
{
    sieve();

    long long i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        mx=max(mx,arr[i]);
    }

    pre();
    solve(0,0);
    printf("%lld\n",ans);



    return 0;
}











