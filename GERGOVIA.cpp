#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,j,k,temp;
    long long ans=0;
    long long sum=0;

    scanf("%lld",&n);

    while(n!=0)
    {
        sum=0;
        ans=0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&temp);

            sum += temp;

            ans += abs(sum);
        }

        printf("%lld\n",ans);

        scanf("%lld",&n);
    }

    return 0;
}








