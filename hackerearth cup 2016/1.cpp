#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long sum[101000];

long long getSum(long long x,long long y){
    long long ans=sum[y];
    if(x)
        ans -= sum[x-1];
    return ans;
}

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld%lld",&n,&k);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+n);

    sum[0] = arr[0];
    for(i=1;i<n;i++){
        sum[i] = sum[i-1] + arr[i];
    }


    long long ans=0;
    long long day = 1;

    for(i=n-1;i>=0;){
        ans  += day*getSum(max(0LL,i-k+1),i);
        day++;
        i -= k;
    }

    printf("%lld\n",ans);
    return 0;
}
