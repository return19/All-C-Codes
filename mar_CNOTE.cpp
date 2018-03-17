#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,x,y,k,n,i,j;
    long long flag;
    long long pg,c;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        flag=0;
        scanf("%lld%lld%lld%lld",&x,&y,&k,&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld%lld",&pg,&c);

            if(pg>=(x-y)&&c<=k)
            {
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("UnluckyChef\n");
        }
        else
        {
            printf("LuckyChef\n");
        }

    }
    return 0;
}
