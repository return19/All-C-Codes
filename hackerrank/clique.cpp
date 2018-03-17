#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k;
    long long x,y,ans;
    long long n,m;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&m);


        if(m==(n*(n-1))/2)
        {
            printf("%lld\n",n);
            continue;
        }
        else if(m==0)
        {
            printf("1\n");
            continue;
        }

        x=m-n;

        ans=2;

        for(j=2;;j++)
        {
            if( (j*(j-1))/2 - (j-1) > x )
                break;

            ans=j;
        }

        printf("%lld\n",ans);

    }

    return 0;
}
