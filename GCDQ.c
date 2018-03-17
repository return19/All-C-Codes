#include<stdio.h>


long long arr[100210];

inline long long gcd(long long u, long long v)
{
  long long shift;

  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;

  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }

  while ((u & 1) == 0)
    u >>= 1;

  /* From here on, u is always odd. */
  do {
       /* remove all factors of 2 in v -- they are not common */
       /*   note: v is not zero, so while will terminate */
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;

       /* Now u and v are both odd. Swap if necessary so u <= v,
          then set v = v - u (which is even). For bignums, the
          swapping is just pointer movement, and the subtraction
          can be done in-place. */
       if (u > v) {
         long long t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);

  /* restore common factors of 2 */
  return u << shift;
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
    scanf("%lld",&test);

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
                    /*a=ans;
                    b=arr[k];
                    while(b!=0){
                    x = a % b;
                    a = b;
                    b = x;
                    }*/

                    ans=gcd(ans,arr[k]);

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























