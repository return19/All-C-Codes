#include<bits/stdc++.h>
using namespace std;

long long arr[310];

long long c[10]={1,2,5,10,20,50,100};

int main()
{
    long long i,j,k;

    long long n;

    scanf("%lld",&n);

    arr[0]=1;

    for(i=0;i<=6;i++)
    {
        for(j=c[i];j<=n;j++)
        {
            if(arr[j-c[i]])
                arr[j]+=arr[j-c[i]];
        }
    }

    printf("%lld\n",arr[n]);

    return 0;
}
