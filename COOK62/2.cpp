#include<bits/stdc++.h>
using namespace std;

long long arr[101000];



int main()
{
    long long test,i,j,k;
    long long t;
    long long n;
    long long x,y,z;
    long long sz=0;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        sz=0;

        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);

            if(i==0)
            {
                arr[sz]=x;
                sz++;
                continue;
            }

            y=lower_bound(arr,arr+sz,x)-arr;
            z=upper_bound(arr,arr+sz,x)-arr;

            if(x<arr[0])
            {
                arr[0]=x;
                continue;
            }

            if(x>=arr[sz-1])
            {
                arr[sz]=x;
                sz++;
                continue;
            }

            arr[z]=x;
        }

        printf("%lld ",sz);
        for(i=0;i<sz;i++)
            printf("%lld ",arr[i]);
        printf("\n");


    }

    return 0;
}

