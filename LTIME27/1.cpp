#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k;
    long long n;

    long long mini=99999999;
    long long temp;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        mini=99999999;
        for(j=0;j<n;j++){
            scanf("%lld",&temp);

            mini=min(mini,temp);
        }

        printf("%lld\n",mini*(n-1));

    }

    return 0;
}
