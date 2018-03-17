#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[110000];

int main()
{

    unsigned long long i,j,k;

    unsigned long long n,x;

    scanf("%llu%llu",&n,&x);

    for(i=0;i<n;i++)
    {
        scanf("%llu",&arr[i]);
    }

    sort(arr,arr+n);

    unsigned long long sum=0;

    for(i=0;i<n;i++)
    {
        sum+=(x*(arr[i]));

        if(x!=1)
            x--;
    }

    printf("%llu\n",sum);

    return 0;
}




















