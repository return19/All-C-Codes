#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[11000000];
long long M=1000000007;
long long power2(long long a,long long b)
{
    long long ph;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ph=power2(a,b/2);

    if(b&1)//odd
    {
        return (((ph*ph)%M)*a)%M;
    }
    else
    {
        return (ph*ph)%M;
    }
}

map<long long,long long> memo;

int main()
{
    long long i,j,k;
    long long t,test;
    long long ma,mj;
    long long ans;
    long long sum=1;
    arr[0]=0;
    arr[1]=1;

    for(i=2;i<=10;i++)
    {
        arr[i]=(i + 2 + 2*(sum))%M;
        sum=(sum + arr[i])%M;
        cout<<i<<" "<<arr[i]<<" "<<memo[arr[i]]<<endl;

        memo[arr[i]]++;
    }
    cout<<" done"<<endl;


    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        ma=power2(2,n-1);
        mj=arr[n];

       // cout<<"ma : "<<ma<<"   mj : "<<mj<<endl;

        ans=mj-ma;

        if(ans<0)
            ans=ans+M;

        printf("%lld\n",ans);
    }


    return 0;
}








