#include<bits/stdc++.h>
using namespace std;
// B
long long arr[101000];
long long mx[101000];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

    mx[n-1]=arr[n-1];

    for(i=n-2;i>=0;i--)
        mx[i]=max(arr[i],mx[i+1]);

    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("0\n");
        }else{
            if(arr[i]>mx[i+1])
                printf("0 ");
            else
                printf("%lld ",mx[i+1]-arr[i]+1);
        }
    }

    return 0;
}

