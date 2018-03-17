#include<bits/stdc++.h>
using namespace std;

long long sum(long long x)
{
    return x*(x+1)/2;
}

long long solve(long long n)
{
    long long i,j,k;
    long long ans=0;

    ans=0;

        j=10;

        while(n/j!=0)
        {
            ans += (n/j)*(45*(j/10));

            k=n/(j/10);
            k=k%10;

            if(k!=0)
            {
                ans += (sum(k-1))*(j/10);
                ans += k*(n%(j/10) + 1);
            }

            j=j*10;
        }

        k=n/(j/10);
        k=k%10;


        ans += (sum(k-1))*(j/10);
        ans += k*(n%(j/10) + 1);

    return ans;
}

int main()
{
    long long test,i,j,k;
    long long n;
    long long a,b;

    scanf("%lld%lld",&a,&b);

    while(a!=-1&&b!=-1)
    {
        printf("%lld\n",solve(b)-solve(a-1));

        scanf("%lld%lld",&a,&b);
    }


    return 0;
}
