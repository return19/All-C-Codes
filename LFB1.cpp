#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

int main()
{
    long long test,i,j,n,max1=0,temp;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&temp);
        max1=0;
        for(j=0;j<temp;j++){
            scanf("%lld",&n);
            if(max1<n)
                max1=n;
            memo[n]++;
        }
        n=memo[max1];
        temp=1;
        for(j=0;j<n;j++)
        {
            temp=(temp*2)%1000000007;
        }
        printf("%lld\n",temp-1);
        memo.clear();
    }
    return 0;

}
