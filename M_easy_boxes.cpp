#include<bits/stdc++.h>
using namespace std;

long long arr[1001000];

int main()
{
    long long n,m,q,l,r,i,j,k,x;
    long long sum;

    scanf("%lld",&n);


        scanf("%lld",&m);

        for(j=0;j<m;j++)
        {
            scanf("%lld%lld",&l,&r);
            l--;
            r--;
            for(k=l;k<=r;k++)
                arr[k]++;
        }

        scanf("%lld",&q);

        for(j=0;j<q;j++)
        {
            sum=0;
            scanf("%lld",&x);
            for(k=0;k<n;k++)
            {
                if(arr[k]>=x)
                    sum++;
            }

            printf("%lld\n",sum);
        }


    return 0;
}
