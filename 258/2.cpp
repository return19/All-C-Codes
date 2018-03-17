#include<bits/stdc++.h>
using namespace std;

long long a[200000];

int main()
{
    long long i,j,k;
    long long n;
    long long f1,f2;
    scanf("%lld",&n);

    for(long long i=0;i<n;i++)
        scanf("%lld",&a[i]);


    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]){
            break;
        }
    }

    if(i<n-1)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[j-1])
                break;
        }
    }
    else
    {
        printf("yes\n");
        printf("1 1");
        return 0;
    }

    if(j<n)
    {
        for(k=j;k<n-1;k++)
        {
            if(a[k]>a[k+1])
            {
                printf("no");
                return 0;
            }
        }

        if(k==n-1)
        {
            if(i==0){
                if(a[i]<=a[j]){
                    printf("yes\n");
                    printf("%lld %lld",i+1,j);
                }
                else
                {
                    printf("no");
                    return 0;
                }
            }
            else
            {
                if(a[i]<=a[j] && a[i-1]<=a[j-1]){
                    printf("yes\n");
                    printf("%lld %lld",i+1,j);
                }
                else
                {
                    printf("no");
                    return 0;
                }
            }
        }
    }
    else
    {
        printf("yes\n");
        printf("%lld %lld",i+1,j);
    }


    return 0;
}

