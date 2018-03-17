#include<bits/stdc++.h>
using namespace std;

long long arr[10000010];

int main()
{
    long long test,i,j,k,n,w,q;

    long long sum=0;
    long long a,b;
    long long c1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&w);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        scanf("%lld",&q);

        for(j=0;j<q;j++)
        {
            scanf("%lld%lld",&a,&b);

            arr[a-1]=b;

            if(w==1)
            {
                printf("%lld\n",n);
                continue;
            }

            sum=0;

            for(k=0;k<n;k++)
            {
                c1=1;

                while(arr[k+1]==arr[k]&&k<n-1)
                {
                    c1++;
                    k++;
                }

                if(c1>=w)
                {
                    sum=sum+c1-w+1;
                }
            }

            printf("%lld\n",sum);
        }
    }
}











