#include<bits/stdc++.h>
using namespace std;

map<long long,long long> l,r;

long long arr[201000];

int main()
{
    long long i,j;

    long long n,k;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);

        r[arr[i]]++;
    }

    long long ans=0;

    for(i=0;i<n;i++)
    {
        r[arr[i]]--;

        if(arr[i]%k==0){
            ans += l[arr[i]/k]*r[arr[i]*k];
        }
        l[arr[i]]++;
    }

    printf("%lld\n",ans);


    return 0;
}
