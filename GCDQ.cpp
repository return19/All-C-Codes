#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[100210];

/*unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    while (a != b)
    {
        if (a > b)
        {
            return gcd(a - b, b);
        }
        else
        {
            return gcd(a, b - a);
        }
    }
    return a;
}*/

unsigned long long gcd(unsigned long long n,unsigned long long m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }

int main()
{
    unsigned long long test,n,q,i,j,k,ans,l,r,flag;
    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&n,&q);

        for(j=0;j<n;j++)
        {
            scanf("%llu",&arr[j]);
        }


        for(j=0;j<q;j++)
        {
            scanf("%llu%llu",&l,&r);
            flag=0;
            for(k=0;k<n;k++)
            {
                if(k==l-1)
                {
                    k=k+(r-l);
                    continue;
                }
                /*if(flag==0)
                {
                    flag=1;
                    ans=arr[k];
                }
                else
                {
                    ans=gcd(ans,arr[k]);
                }*/
                if(flag!=0)
                {
                    ans=gcd(ans,arr[k]);

                }
                else
                {
                    flag=1;
                    ans=arr[k];
                }
            }
            printf("%llu\n",ans);
        }
    }
    return 0;
}























