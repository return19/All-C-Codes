#include<bits/stdc++.h>
using namespace std;

long long v;
long long arr[10];
long long mn=LLONG_MAX;

pair<long long,long long> memo[101000];
long long base[101000];

long long power(long long x,long long y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;

    long long hf=power(x,y/2);

    if(y&1)
    {
        return hf*hf*x;
    }
    return hf*hf;
}

pair<long long,long long> solve(long long v)
{
    if(v<mn)
        return make_pair(0,0);

    if(base[v]==1)
        return memo[v];
    base[v]=1;

    long long i;
    long long num=0;
    long long ans=0;
    long long idx=0;

    pair<long long,long long> p;

    for(i=1;i<=9;i++)
    {
        if(v>=arr[i]){
            p=solve(v-arr[i]);

            if(num<=p.second)
            {
                num=p.second;
                ans=p.first;
                idx=i;
            }
        }
    }

    if(num==0)
        return memo[v]=make_pair(idx,1);

    return memo[v]=make_pair(idx*power(10,num) + ans,num+1);
}

int main()
{
    long long i,j,k;

    scanf("%lld",&v);

    for(i=1;i<=9;i++){
        scanf("%lld",&arr[i]);

        mn=min(mn,arr[i]);
    }

    if(mn>v)
    {
        printf("-1\n");
        return 0;
    }

    pair<long long,long long> ans=solve(v);

    printf("%lld\n",ans.first);

    return 0;
}
