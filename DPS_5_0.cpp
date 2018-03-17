#include<bits/stdc++.h>
using namespace std;

long long arr[500010];

int main()
{
    long long n,i,j,k,count1=0,sum=0,subsum1,subsum2;
    scanf("%lld",&n);

    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        sum=sum+arr[i];
    }
    if(sum%3!=0)
    {
        printf("0\n");
        return 0;
    }
    subsum1=0;
    for(i=0;i<n-2;i++)
    {
        subsum1=subsum1+arr[i];
        if(subsum1==sum/3)
        {
            subsum2=0;
            for(j=i+1;j<n-1;j++)
            {
                subsum2=subsum2+arr[j];
                if(subsum2==sum/3)
                    count1++;
            }
        }
    }

    printf("%lld\n",count1);
    return 0;
}
