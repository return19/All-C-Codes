#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;
    long long x;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);

        memo.clear();
        long long ans=0;

        for(i=0;i<n;i++){
            scanf("%lld",&x);

            if(memo.find(x)==memo.end()){
                memo[x]=1;
                ans += x;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}

