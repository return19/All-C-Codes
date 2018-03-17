#include<bits/stdc++.h>
using namespace std;

long long arr[6100];


long long lis( long long arr[], long long n )
{
   long long *lis, i, j, max = 0;
   lis = (long long*) malloc ( sizeof( long long ) * n );


   for ( i = 0; i < n; i++ )
      lis[i] = 1;


   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;


   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];


   free( lis );

   return max;
}

int main()
{
    long long test,i,j,k,n;
    long long q;
    long long l,r;
    long long ans;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        scanf("%lld%lld",&l,&r);
        ans=lis(arr+l-1,r-l+1);

        printf("%lld\n",ans);
    }

    return 0;
}












