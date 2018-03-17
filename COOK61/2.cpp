#include<bits/stdc++.h>
using namespace std;

long long power_cal(long long x,long long y)
{
    if(y==0)
        return 1;

    long long t=power_cal(x,y/2);

    if(y%2==0)
    {
        return t*t;
    }
    else
    {
        return t*t*x;
    }
}

int main()
{
    long long test,i,j,k;
    long long n;
    long long t,ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        ans=1;
        scanf("%lld",&n);

        t=n;
        k=0;

        if(t==0)
        {
            printf("-1\n");
            continue;
        }
        else if(t==1)
        {
            printf("2\n");
            continue;
        }

        while(t!=0)
        {
            j=t%2;

            if(j==0)
            {
                ans=0;
                break;
            }
            k++;
            t=t>>1;
        }

        if(ans==0)
        {
            printf("-1\n");
            continue;
        }

        ans=power_cal(2,k-1)-1;

        printf("%lld\n",ans);

    }

    return 0;
}

