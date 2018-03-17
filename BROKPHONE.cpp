#include<bits/stdc++.h>
using namespace std;

long long arr[100100];
map<long long,long long> memo;
map<long long,long long>::iterator it;

int main()
{
    long long test,i,j,k,n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();

        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        for(j=0;j<n-1;j++)
        {
            if(arr[j]!=arr[j+1])
            {
                memo[j]++;
                memo[j+1]++;
            }
        }

        long long count1=0;

        for(it=memo.begin();it!=memo.end();it++)
        {
            if(it->second>0)
                count1++;
        }

        printf("%lld\n",count1);
    }

    return 0;
}
