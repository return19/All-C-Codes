#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long test,i,j,k,t;
    long long n;
    long long ans;


    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        sort(arr,arr+n);

        ans=0;

        for(i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
                ans=1;
        }

        if(ans==1)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}











