#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long test,n,i,j,k;
    unsigned long long sum=0,sum_till=0;
    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        sum_till=0;
        scanf("%llu",&n);

        for(j=1;j<n;j++)
        {
            sum_till=sum_till+j;

            sum=sum+2*sum_till;
        }

        printf("%llu\n",sum);
    }

    return 0;
}
