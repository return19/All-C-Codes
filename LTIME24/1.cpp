#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[1100000];

int main()
{
    unsigned long long test,i,j,k,n;
    unsigned long long t;

    scanf("%llu",&test);

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&n,&k);

        for(j=0;j<n;j++)
        {
            scanf("%llu",&arr[j]);
        }

        unsigned long long sum=0;

        for(j=0;j<n;j++)
        {
            t=arr[j]/k;
            t=(t+1)*k;


            if(arr[j]<k)
            {
                sum=sum+t-arr[j];
                continue;
            }
            sum=sum+min(arr[j]%k,t-arr[j]);
        }

        printf("%llu\n",sum);
    }

    return 0;
}


















