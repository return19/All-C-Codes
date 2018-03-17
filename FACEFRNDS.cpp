#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;
map<long long,long long>::iterator it;

int main()
{
    long long n,m,i,j,k,id;
    long long count1=0;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        count1=0;
        scanf("%lld",&id);
        memo[id]=5;
        scanf("%lld",&m);

        for(j=0;j<m;j++)
        {
            scanf("%lld",&id);
            if(memo[id]!=5)
                memo[id]=1;
        }
    }
    for(it=memo.begin();it!=memo.end();it++)
    {
        if(it->second!=5)
            count1++;
    }

    printf("%lld\n",count1);



}
