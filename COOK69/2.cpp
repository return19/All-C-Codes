#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j,k;
    long long test,t;
    long long l,r;

    for(i=1;i<=100010;i+=2)
    {
        k=1;
        for(j=i*k;j<=100010;j=i*k)
        {
            arr[j]+=i;
            k++;
        }
    }

    for(i=2;i<=100010;i++)
        arr[i]+=arr[i-1];



    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",arr[r]-arr[l-1]);
    }
    return 0;
}

