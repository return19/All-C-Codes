#include<bits/stdc++.h>
using namespace std;

long long solve(long long x){
    long long ans=0;

    while(x!=0)
    {
        ans += x%10;
        x/=10;
    }
    return ans;
}

int main()
{
    long long i,j,k;
    long long n;
    long long ans=0;

    scanf("%lld",&n);

    for(i=n-200;i<=n;i++){
        if(i + solve(i) + solve(solve(i)) == n)
            ans++;
    }

    printf("%lld\n",ans);

    return 0;
}
