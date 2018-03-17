#include<bits/stdc++.h>
using namespace std;

long long arr[10110];

int main()
{
    long long i,j,k;
    long long test;
    long long n,u;
    long long x,y,val;
    long long q;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        scanf("%lld%lld",&n,&u);

        memset(arr,0,sizeof(long long)*(n+5));

        for(j=0;j<u;j++)
        {
            scanf("%lld%lld%lld",&x,&y,&val);

            arr[x]+=val;
            arr[y+1]+=(-1*val);
        }

        for(j=1;j<n;j++)
        {
            arr[j]+=arr[j-1];
        }

        scanf("%lld",&q);

        for(j=0;j<q;j++)
        {
            scanf("%lld",&x);

            printf("%lld\n",arr[x]);
        }
    }

    return 0;

}










