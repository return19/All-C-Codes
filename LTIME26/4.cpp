#include<bits/stdc++.h>
using namespace std;

long long gcd(long long n,long long m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }

int main()
{
    long long test,i,j,k;
    long long n;
    long long d;
    long long ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&d);

        ans=0;

        for(j=1;j<=n;j++)
        {
            for(k=j;k<=n;k++)
            {
                if(__gcd(j,k)==d)
                    ans++;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
