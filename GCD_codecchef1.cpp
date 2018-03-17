#include<iostream>
#include<cstdio>
using namespace std;
#include<stdio.h>


long long arr[100210];


 void scanint(long long &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}
/*long long gcd(long long n,long long m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }*/
	/* long long gcd(long long a, long long b){
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 ){
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}*/

/*inline long long gcd(long long a,long long b) {
  long long r, i;
  while(b!=0){
    x = a % b;
    a = b;
    b = x;
  }
  return a;
}
*/
int main()
{
    long long test,n,q,i,j,k,ans,l,r,flag,x,a,b;
    scanint(test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&q);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }


        for(j=0;j<q;j++)
        {
            scanf("%lld%lld",&l,&r);
            flag=0;
            for(k=0;k<n;k++)
            {
                if(k==l-1)
                {
                    k=k+(r-l);
                    continue;
                }

                if(flag!=0)
                {
                    a=ans;
                    b=arr[k];
                    while(b!=0){
                    x = a % b;
                    a = b;
                    b = x;
                    }

                    ans=a;

                }
                else
                {
                    flag=1;
                    ans=arr[k];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
