#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long test,i,j,k;
    unsigned long long n;
    unsigned long long x1,x2,x3;
    unsigned long long ans;

    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu",&n);
        n--;

        x1=n/3;

        x2=n/5;

        x3=n/15;

        x1=x1*(x1+1);
        x1=x1/2;

        x2=x2*(x2+1);
        x2=x2/2;

        x3=x3*(x3+1);
        x3=x3/2;



        ans=3*x1+5*x2-15*x3;

        printf("%llu\n",ans);
    }

    return 0;
}
