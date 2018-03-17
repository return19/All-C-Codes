#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

int main()
{
    long long i,j,k;
    long long test,t;
    long long n,s;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();
        scanf("%lld%lld",&n,&s);
        long long temp=0;
        long long ans=0;
        for(i=1;s>=temp;i++){
            temp=((n*(n-1))/2)*i;

            if(temp>=s)  break;

            if(memo[(s-temp)%n]==1)
                break;
            memo[(s-temp)%n]=1;
            if((s-temp)%n==0){
                ans=1;
                break;
            }
        }

        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
