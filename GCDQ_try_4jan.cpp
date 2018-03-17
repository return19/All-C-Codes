#include<iostream>
#include<cstdio>
using namespace std;
#include<stdio.h>


long arr[100210];
long dp[10210][10210];
long n;

long gcd(long a,long b)
{

  long r, i,x;
  while(b!=0){
    x = a % b;
    a = b;
    b = x;
  }
  return a;


}

 void scanint(long &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}


void construct()
{
    long i,j;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=i;j--)
        {

            if(i==0)
            {
                if(j==n-1)
                    continue;
                if(j==n-2)
                {
                    dp[i][j]=arr[n-1];
                }
                else
                {
                    dp[i][j]=gcd(dp[i][j+1],arr[j+1]);
                }
            }
            else
            {
                /*if(i==1&&j==n-1)
                {
                    dp[i][j]=arr[i-1];
                    continue;
                }
                else if()*/
                if(j==n-1)
                {
                    if(i==1)
                        dp[i][j]=arr[i-1];
                    else
                        dp[i][j]=gcd(arr[i-1],dp[i-1][j]);
                    continue;
                }
                dp[i][j]=gcd(dp[i-1][j],dp[i][j+1]);
            }
        }
    }

}



/*long gcd(long n,long m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }*/
	/* long gcd(long a, long b){
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 ){
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}*/

/*inline long gcd(long a,long b) {
  long r, i;
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
    long test,q,i,j,k,ans,l,r,flag,x,a,b;
    scanint(test);

    for(i=0;i<test;i++)
    {
        //scanf("%lld%lld",&n,&q);
        scanint(n);
        scanint(q);
        for(j=0;j<n;j++)
        {
           // scanf("%lld",&arr[j]);
           scanint(arr[j]);
        }

        construct();

        for(j=0;j<q;j++)
        {
            //scanf("%lld%lld",&l,&r);
            scanint(l);
            scanint(r);

            printf("%lld\n",dp[l-1][r-1]);
            /*flag=0;
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
            }*/
            //printf("%lld\n",ans);
        }
    }
    return 0;
}
