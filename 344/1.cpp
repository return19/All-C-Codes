#include<bits/stdc++.h>
using namespace std;

long long a[101000];
long long b[101000];

int main()
{
    long long i,j,k;
    long long n;
    scanf("%lld",&n);
    long long ans1=0,ans2=0;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        ans1|=a[i];
    }
    for(i=0;i<n;i++){
        scanf("%lld",&b[i]);
        ans2|=b[i];
    }

    printf("%lld\n",ans1+ans2);
    return 0;

    long long mx=LLONG_MIN;

    for(i=0;i<n;i++)
    {
        long long cur1=0,cur2=0;

        for(j=i;j<n;j++)
        {
            cur1=cur1|a[j];
            cur2=cur2|b[j];
            mx=max(mx,cur1+cur2);
           // cout<<cur1+cur2<<endl;
        }
    }

    printf("%lld\n",mx);
    return 0;
}
