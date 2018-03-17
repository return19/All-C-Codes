#include<bits/stdc++.h>
using namespace std;


long long time_taken[10010];
long long prof[10010];

int main()
{
    long long test,n,k,i,j,sum;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&k);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&time_taken[j]);
            time_taken[j]=k/time_taken[j];
        }
        sum=0;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&prof[j]);
            if(sum<prof[j]*time_taken[j])
                sum=prof[j]*time_taken[j];
        }
        printf("%lld\n",sum);
    }
    return 0;
}


















