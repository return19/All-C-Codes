#include<bits/stdc++.h>
using namespace std;

long long memo[1000010];

void pf(long long n)
{
    long long i,j;
    long long sqt=sqrt(n);
    for(i=2;i<=sqt+1;i++)
    {
        if(n%i==0)
        {
            while(n%i==0){
                memo[i]++;
                n=n/i;
            }
        }
    }
    if(n!=1)
    {
        memo[n]++;
    }
}

int main()
{
    long long test,i,j,k,n,temp,max1,sum;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        max1=0;
        memset(memo,0,sizeof(memo));
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&temp);
            if(max1<temp)
                max1=temp;
            pf(temp);
        }
        sum=1;
        for(j=2;j<=max1;j++)
        {
            sum=sum*(memo[j]+1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}






