#include<bits/stdc++.h>
using namespace std;

long long arr[500100];

map<long long,long long> memo;

int main()
{
    long long n,i,j,k;
    long long temp;

    arr[0]=0;
    for(i=1;i<500010;i++)
    {
        temp=arr[i-1]-i;

        if(temp<=0||memo[temp])
        {
            temp=arr[i-1]+i;
            arr[i]=temp;
            memo[temp]=1;

        }
        else
        {
            arr[i]=temp;
            memo[temp]=1;
        }
    }


    scanf("%lld",&n);

    while(n!=-1)
    {
        printf("%lld\n",arr[n]);

        scanf("%lld",&n);
    }

    return 0;
}
