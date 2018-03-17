#include<bits/stdc++.h>
using namespace std;

long long arr[1010000];
long long sum[1010000];

long long ans[1010000];
long long mns[1010000];

long long M=1000000007;

int main()
{
    long long i,j;
    long long n,k;

    scanf("%lld%lld",&n,&k);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        sum[i] = (sum[i-1] + arr[i])%M;
    }

    for(i=1;i<=k;i++){
        mns[1]=(mns[1] + ((((i*i)-(i-1)*(i-1))%M)*arr[i])%M)%M;
    }

    for(i=2;i<=n-k+1;i++)
    {
        mns[i]=mns[i-1] + ((((k*k)-(k-1)*(k-1))%M)*arr[i+k-1])%M;
        mns[i] = mns[i]-2*(sum[i+k-2]-sum[i-1]) - arr[i-1];

        if(mns[i]<0)
            mns[i]+=M;
    }

   /* for(i=1;i<=n-k+1;i++)
        cout<<mns[i]<<" ";
    cout<<endl;*/

    for(i=1;i<=k;i++)
    {
        ans[1]= (ans[1]+ (((i*i)%M)*arr[i])%M)%M;
    }

    for(i=2;i<=n-k+1;i++)
    {
        ans[i]=(ans[i-1] + (((k*k)%M)*arr[i+k-1])%M)%M;
        ans[i] =ans[i] - mns[i-1];

        if(ans[i]<0)
            ans[i]+=M;
    }

    for(i=1;i<=n-k+1;i++)
        printf("%lld ",ans[i]%M);

    return 0;
}


















