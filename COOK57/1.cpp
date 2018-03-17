#include<bits/stdc++.h>
using namespace std;

long long arr[51000];

int main()
{
    long long test,i,j,k;
    long long n;
    long long a1,a2,a3;
    long long sum;


    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
            sum=sum+arr[j];
        }

        sum=sum/(n-1);

        for(j=0;j<n;j++)
        {
            printf("%lld ",sum-arr[j]);
        }
        printf("\n");
    }

    return 0;
}
