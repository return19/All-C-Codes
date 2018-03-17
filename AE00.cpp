#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;

    long long n;

    scanf("%lld",&n);

    long long ans=1;

    for(i=2;i<=n;i++)
    {
        long long temp=i;

        ans++;

        for(j=2;j*j<=i;j++)
        {
            if(temp%j==0)
                ans++;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
