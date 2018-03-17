#include<bits/stdc++.h>
using namespace std;

long long arr[1110];

long long count1=0;

long long max1=-1;

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long calc(long long n)
{
    long long i,j,k;
    long long p,c;
    long long start=1,sc=1;
    long long v1,v2;

    p=n;

    if(n%2==0)
    {
        n=n/2;
    }
    else
    {
        n=n/2+1;
    }

    c=n+start;
    while(p>c)
    {
        start=start+(1<<sc);
        sc++;

        p=c;
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=n/2+1;
        }
        c=n+start;

    }
    sc--;

    count1+=p;

    return (p-(start-(1<<sc)));
}

int main()
{
    long long test,i,j,k,n;
    long long  dec;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        max1=-1;

        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);

            max1=max2(max1,arr[j]);
        }

        sort(arr,arr+n,greater<long long>());

        for(j=0;j<n;j++)
        {
            if(arr[j]<=0)
                break;

            dec=calc(arr[j]);

            for(k=j+1;k<n;k++)
            {
                arr[k]=arr[k]-dec;
            }
        }

        printf("Case #%lld: %lld\n",i+1,min2(count1,max1));
    }

    return 0;
}














