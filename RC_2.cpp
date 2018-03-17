#include<bits/stdc++.h>
using namespace std;

long long arr[10010];

int main()
{
    long long test,i,j,k,n;
    long long max1,min1,temp;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        max1=-99999999999;

        min1=arr[0];
        for(j=1;j<n;j++)
        {
            if(arr[j]-min1>max1)
                max1=arr[j]-min1;
            if(min1>arr[j])
            {
                min1=arr[j];
            }
        }

        printf("%lld\n",max1);
    }
    return 0;
}
