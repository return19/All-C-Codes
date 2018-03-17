#include<bits/stdc++.h>
using namespace std;

long long arr[501000];

int main()
{
    long long i,j;
    long long n,k;
    long long sum,ans;
    long long idx;
    long long temp;

    scanf("%lld%lld",&n,&k);

    sum=0;

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    for(i=0;i<k;i++)
        sum+=arr[i];

    ans=sum;
    idx=0;

    for(i=k;i<n;i++)
    {
        sum -= arr[i-k];
        sum += arr[i];

        if(sum<ans)
        {
            ans=sum;
            idx=i-k+1;
        }
    }

    printf("%lld\n",idx+1);

    return 0;
}
