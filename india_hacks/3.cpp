#include<bits/stdc++.h>
using namespace std;

long long arr[1010000];

long long M=1e9 +7;

long long mns[1010000];

long long sum[1010000];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld%lld",&n,&k);

    for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);

    for(i=1;i<=n;i++)
        sum[i]=sum[i-1]+arr[i];

    j=3;

    /*for(i=2;i<k;i++)
    {
        mns[1]+=j*arr[i];
        j+=2;
    }*/
    mns[1]-=arr[1];
    mns[1]+=arr[1+k];

    for(i=2;i<n-k+1;i++)
    {
        mns[i]=mns[i-1];
        mns[i]-=arr[i];
        mns[i]-= (-sum[i]+sum[i+k-2])*2;
        mns[i]+=k*k*arr[i+k-1];
    }
    long long sum1=0;

    for(i=1;i<=k;i++)
        cout<<mns[i]<<" ";
    cout<<endl;

    for(i=1;i<=k;i++)
        sum1=sum1 + i*i*arr[i];

    for(i=1;i<=n-k+1;i++)
    {


        sum1=sum1+mns[i-1];

        printf("%lld ",sum1);
    }

    return 0;
}
