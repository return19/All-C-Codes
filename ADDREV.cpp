#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,t,i,j,k;
    long long n,m;
    long long temp;
    long long ans;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&m);

        temp=0;

        while(n!=0)
        {
            temp= temp*10 + n%10;
            n /= 10;
        }

        n=temp;

        temp=0;

        while(m!=0)
        {
            temp= temp*10 + m%10;
            m /= 10;
        }

        m=temp;

        ans =  n+m;


        temp=0;

        while(ans!=0)
        {
            temp= temp*10 + ans%10;
            ans /= 10;
        }

        ans=temp;

        printf("%lld\n",ans);

    }

    return 0;
}
