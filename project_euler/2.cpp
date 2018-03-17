#include<bits/stdc++.h>
using namespace std;



unsigned long long solve(unsigned long long n)
{
    unsigned long long a,b,c,sum=0;
    a=1;
    b=1;
    c=a+b;



    while(c<=n)
    {
        sum+=c;
        //memo[c]=sum;

        a=b;
        b=c;
        c=a+b;

        a=b;
        b=c;
        c=a+b;

        a=b;
        b=c;
        c=a+b;

    }

    return sum;

}

int main()
{
    unsigned long long test,i,j,k;
    unsigned long long n;



    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu",&n);

        printf("%llu\n",solve(n));
    }

    return 0;
}
