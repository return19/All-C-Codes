#include<bits/stdc++.h>
using namespace std;

long long arr[110];
long long n;

int main()
{
    long long test,i,j,k,t;

    scanf("%lld",&test);

    long long ans=0;

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        ans=0;
        long long sum=0;
        long long pro=1;

        for(i=0;i<n;i++)
        {
            sum=0;
            pro=1;

            for(j=i;j<n;j++)
            {
                sum += arr[j];
                pro *= arr[j];

                if(sum==pro)
                    ans++;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}













