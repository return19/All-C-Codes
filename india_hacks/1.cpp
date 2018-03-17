#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        if(n==1)
        {
            printf("1\n");
        }
        else if(n==2)
        {
            printf("4\n");
        }
        else
            printf("%lld\n",8 + 12*(n-2) + 6*(n-2)*(n-2));
    }


    return 0;
}
