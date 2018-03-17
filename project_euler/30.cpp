#include<bits/stdc++.h>
using namespace std;

long long power(long long x,long long y){
    if(y==0)
        return 1;
    if(y==1)
        return x;
    long long hf = power(x,y/2);
    if(y&1)
        return x*hf*hf;
    return hf*hf;
}

int main()
{
   long long i,j,k;
    long long n;
    scanf("%lld",&n);

    long long ans=0;

    for(i=10;i<1000000;i++){
        long long temp = i;
        long long t=0;
        while(temp){
            t = t + power(temp%10,n);
            temp = temp/10;
        }
        if(t == i)
            ans += i;
    }

    printf("%lld\n",ans);
    return 0;
}












