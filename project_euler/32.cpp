#include<bits/stdc++.h>
using namespace std;

long long n;
long long c[10];
long long check(long long a,long long b,long long cc){
    long long i,j,k;
    for(i=0;i<10;i++)
        c[i]=0;
    while(a){
        c[a%10]++;
        a /= 10;
    }
    while(b){
        c[b%10]++;
        b /= 10;
    }
    while(cc){
        c[cc%10]++;
        cc /= 10;
    }

    for(i=1;i<=n;i++)
        if(c[i]!=1) return 0;
    if(c[0])    return 0;
    for(i=n+1;i<=9;i++)
        if(c[i])    return 0;
    return 1;
}

int main()
{
    long long i,j,k;

    scanf("%lld",&n);
    long long ans=0;
    for(i=1;i<=10000;i++){
        for(j=1;j*j<=i;j++){
            if(i%j==0)
                if(check(j,i/j,i)){
                    ans = ans + i;
                    break;
                }
        }
    }

    printf("%lld\n",ans);
    return 0;
}
