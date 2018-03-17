#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    if(n%2!=0)
    {
        printf("0\n");
        return 0;
    }

    long long x=n/2;

    if(x%2==0)
    {
        printf("%lld\n",x/2 - 1);
    }
    else
        printf("%lld\n",x/2);

    return 0;
}
