#include<bits/stdc++.h>
using namespace std;

long long check(long long x){
    long long rev=0;
    long long t=x;
    while(t){
        rev = rev*10 + t%10;
        t/=10;
    }
    if(x==rev)
        return 1;
    return 0;
}

int main()
{
    long long i,j,k;
    long long n;
    long long ans=0;

    scanf("%lld%lld",&n,&k);

    for(i=1;i<n;i++){
        if(check(i)){
            long long temp = i;
            vector<long long> base;
            while(temp){
                base.push_back(temp%k);
                temp/=k;
            }
            long long f=0;
            for(long long x=base.size()-1,j=0;j<x;j++,x--)
            {
                if(base[j]!=base[x])
                {
                    f=1;
                    break;
                }
            }

           // cout<<i<<" "<<baseVal<<endl;

            if(!f)
                ans += i;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
