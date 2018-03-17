#include<bits/stdc++.h>
using namespace std;

long long arr[201000];

int main()
{
    long long n,k1,k2;
    long long i,j,k;

    scanf("%lld%lld%lld",&n,&k1,&k2);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    long long r=0,x=0;
    long long sum=0;

    long long ans=0,a,b;

    for(i=0;i<n-1;i++)
    {
        r=0;
        x=0;

        for(j=i+1;j<n;j++)
        {
            for(a=i;a<j;a++)
            {
                r += arr[a]|arr[j];
                x += arr[a]^arr[j];
            }

            if(r>k1&&x>k2)
                ans++;
        }
    }

    printf("%lld\n",ans);

    return 0;
}















