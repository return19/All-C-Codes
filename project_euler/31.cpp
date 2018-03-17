#include<bits/stdc++.h>
using namespace std;

long long d[10]={1,2,5,10,20,50,100,200};
long long ans[101000];
long long M = 1e9 + 7;

int main()
{
    long long i,j,k;
    long long test,t;

    ans[0]=1;
    for(i=0;i<8;i++){
        for(j=d[i];j<=100010;j++){
            ans[j] = (ans[j] + ans[j-d[i]])%M;
        }
    }

    scanf("%lld",&test);
    long long n;
    for(t=0;t<test;t++){
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
