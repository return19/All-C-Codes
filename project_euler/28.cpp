#include<bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;

long long power(long long x,long long y){
    if(y==0)
        return 1;
    if(y==1)
        return x%M;
    long long hf = power(x,y/2);
    if(y&1)
        return (((hf*hf)%M)*x)%M;
    return (hf*hf)%M;
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);
        n = n%M;
        long long ans1 = (4*((((n*n)%M)*n)%M))%M;
        ans1 = (ans1 + ((3*((n*n)%M))%M) )%M;
        ans1 = (ans1 + ((8*n)%M) -9+M )%M;
        ans1 = (ans1*power(6,M-2))%M;
        printf("%lld\n",ans1%M);
    }
    return 0;
}
