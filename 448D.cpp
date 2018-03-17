#include<bits/stdc++.h>
using namespace std;

long long n,m;

long long solve(long long x){
    long long i,j,k;
    long long a,b;
    long long prev = 0;
    long long ans = 0;

    for(i=1;i<=m;i++){
        long long temp = (x-1)/i;
        ans += min(n,temp);
    }
    return ans+1;
}

int main()
{
    long long i,j,k;

    scanf("%lld%lld%lld",&n,&m,&k);

    if(k == n*m)
    {
        printf("%lld\n",n*m);
        return 0;
    }

    long long st=1;
    long long ed = n*m;
    long long mid;

    while(st<ed){
        mid = st + (ed-st)/2 + 1;
        long long temp = solve(mid);
       // cout<<mid<<" "<<temp<<" "<<st<<" "<<ed<<endl;

        if(temp <= k)
            st = mid;
        else
            ed = mid-1;
    }

    printf("%lld\n",ed);

    return 0;
}









