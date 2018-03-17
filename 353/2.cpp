#include<bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m;
    long long n,a,b,c,d;

    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);

    long long ans=0;

    for(i=1;i<=n;i++){
        j=b+i-c;
        l=a+j-d;
        m=c+l-b;

        if(i == m+d-a && j>=1 && j<=n && l>=1 && l<=n && m>=1 && m<=n)
            ans++;
    }

    printf("%lld\n",ans*n);

    return 0;
}

