#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

long long csum[101000];

long long s[101000];


long long n;

long long ans;

void sieve()
{
    long long i,j,k;

    for(i=2;i<=n;i++)
    {
        if(s[i]==0)
        {

            ans += csum[i+1];

            j=i*2;

            k=2;

            for(;j<=n;j=j*k)
            {
                s[j]=1;
                k++;
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        if(s[i]==0)
        {
            s[i]=1;
            s[i]+=s[i-1];
        }
        else
            s[i]=s[i-1];
    }

    for(i=0;i<n;i++)
    {
        ans -= s[n-i]*arr[i];
    }

}

int main()
{
    long long i,j,k;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    csum[n+1]=0;

    for(i=n;i>0;i--)
        csum[i]=csum[i+1] + arr[i];

    sieve();

    printf("%lld\n",ans);

    return 0;
}











