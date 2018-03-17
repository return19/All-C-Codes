#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long n,p;

int main()
{
    long long test,i,j,k,t;
    long long ans=0;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&p);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }

        ans=0;
        long long sum=0;

        i=0;
        j=0;
        long long prev=j;

        while(i<n)
        {
            while(j<n && sum<=p)
            {
                sum+=arr[j];
                j++;
            }

            if(j==n && sum<=p)
            {
                long long num=j-i;
                ans= ans + num*(num+1)/2;
                //num=prev-i-1;
               // ans= ans -(num*(num+1))/2;
                break;
            }

            long long num=j-i-1;
            ans= ans + num*(num+1)/2;


            while(i<n && i<=j && sum>p)
            {
                sum-=arr[i];
                i++;
            }
            num=j-i-1;
            ans= ans -(num*(num+1))/2;

        }

        printf("Case #%lld: %lld\n",t+1,ans);
    }

    return 0;
}
