#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k;
    long long n;
    long long sum,min1;
    long long temp;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        min1=99999999;

        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&temp);
            sum=sum+temp;

            if(min1>sum)
                min1=sum;
        }

        if(min1>=0)
        {
            printf("Scenario #%lld: 1\n",i+1);
            continue;
        }
        else
        {
            printf("Scenario #%lld: %lld\n",i+1,min1*(-1)+1);
        }
    }

    return 0;
}










