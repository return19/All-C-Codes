#include<bits/stdc++.h>
using namespace std;
#define M 1000000007


pair<long long,long long> p;

map< pair<long long,long long>,long long > memo;

int main()
{
    long long test,n,i,j,k,q;
    long long s,d;
    long long temp,sum=0;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%lld",&temp);

                p.first=j;
                p.second=temp;
                memo[p]++;

            }
        }

        sum=1;

        scanf("%lld",&q);

        for(j=0;j<q;j++)
        {
            sum=1;
            scanf("%lld%lld",&s,&d);

            if((d-s)!=n+1)
            {
                printf("0\n");
                continue;
            }

            for(k=0;k<n;k++)
            {
                p.first=k;
                p.second=s+1;
                sum=(sum*(memo[p]))%M;
                s=s+1;
                if(sum==0)
                    break;
            }

            printf("%lld\n",sum%M);
        }

    }

    return 0;
}




