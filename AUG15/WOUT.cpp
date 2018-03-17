#include<bits/stdc++.h>
using namespace std;


long long st[1000100];
long long ed[1000100];
long long val[1000100];

int main()
{
    long long test,i,j,k;
    long long n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        scanf("%lld%lld",&n,&k);

        for(j=0;j<=n;j++)
        {
            st[j]=0;
            ed[j]=0;
            val[j]=0;
        }

        for(j=0;j<n;j++)
        {
            long long x,y;

            scanf("%lld%lld",&x,&y);

            st[x]++;
            ed[y+1]++;
        }

        val[0]=st[0]-ed[0];

        for(j=1;j<n;j++)
        {
            st[j]=st[j]+st[j-1];
            ed[j]=ed[j]+ed[j-1];

            val[j]=st[j]-ed[j];
        }

        long long temp=0;

        for(j=0;j<k;j++)
        {
            temp=temp+val[j];
        }

        long long ans=temp;

        for(j=k;j<n;j++)
        {
            temp=temp+val[j]-val[j-k];
            ans=max(ans,temp);
        }

        printf("%lld\n",n*k-ans);
    }

    return 0;
}













