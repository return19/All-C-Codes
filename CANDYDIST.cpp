#include<bits/stdc++.h>
using namespace std;

long long studs[100100];
long long candy[100100];

int main()
{
    long long n,i,j,k;

    scanf("%lld",&n);

    while(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&studs[i]);

        for(i=0;i<n;i++)
            scanf("%lld",&candy[i]);

        sort(studs,studs+n,greater<long long>());
        sort(candy,candy+n);

        long long sum=0;

        for(i=0;i<n;i++)
        {
            sum=sum+studs[i]*candy[i];
        }

        printf("%lld\n",sum);


        scanf("%lld",&n);
    }

    return 0;
}
