#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j,k;
    long long n,s;

    scanf("%lld%lld",&n,&s);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    long long ans=0;
    long long f=1;
    for(i=0;i<n;i++)
    {
        if(arr[i]<=s)
        {
            ans++;
        }
        else
        {
            if(f!=1)
                break;
            else
                f=0;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
