#include<bits/stdc++.h>
using namespace std;

long long n;
map<long long,long long> memo;
map<long long,long long>::iterator it;
long long arr[1010000];
int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        memo.clear();
        scanf("%lld",&n);
        long long ans=0;

        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }

        memo[arr[0]]=1;
        for(i=1;i<n;i++){
            arr[i]+=arr[i-1];
            memo[arr[i]]++;
        }

        for(it=memo.begin();it!=memo.end();it++){
            if(it->first ==0)
                ans += (it->second)*(it->second + 1)/2;
            else
                ans += (it->second)*(it->second - 1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}







