#include<bits/stdc++.h>
using namespace std;

long long arr[300100];

int main()
{
    long long n,m,i,j,k,max1=-1,sum_till=0;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    j=0;
    for(i=0;i<n;i++)
    {
        sum_till+=arr[i];

        while(sum_till>m)
        {
            sum_till=sum_till-arr[j];
            j++;
        }

        if(max1<sum_till)
            max1=sum_till;
    }

    printf("%lld\n",max1);
    return 0;
}
