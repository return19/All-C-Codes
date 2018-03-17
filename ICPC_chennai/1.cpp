#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,t,i,j,k;
    long long ans;
    long long temp;

    long long n;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&k);

        ans=0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp);

            temp += k;

            if(temp%7==0)
                ans++;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
