#include<bits/stdc++.h>
using namespace std;

long long b[110000];
long long g[110000];

int main()
{
    long long n,k;
    long long i,j;
    long long ans=0;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
    }

    for(i=0;i<n;i++)
    {
        scanf("%lld",&g[i]);
    }

    sort(b,b+n);
    sort(g,g+n);

    i=0;
    j=0;

    while(i < n){
    while(j < n){
        if(b[i]-g[j] <= k){
            if(b[i]-g[j] >= -1 * k){
                ans++;
                j++;
            }
            break;
        }
        j++;
    }
    i++;
}

    printf("%lld\n",ans);



    return 0;
}
