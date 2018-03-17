#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[33];
long long b[33];
long long p2[33];

long long x,y;

void calc()
{
    long long i,j;
    p2[0]=1;

    for(i=1;i<=32;i++)
    {
        p2[i]=p2[i-1]*2;
    }
}

long long solve()
{
    long long i,j,k;
    i=-1;
    j=-1;

    long long x1,y1;

    x1=x;
    y1=y;

    long long d=y1-x1+1;

    while(x!=0)
    {
        a[++i]=x%2;
        x=x/2;
    }

    while(y!=0)
    {
        b[++j]=y%2;
        y=y/2;
    }

    long long ans=0;

    for(k=0;k<=i;k++)
    {
        if(d<=p2[k])
        {
            if(a[k]&b[k])
                ans+=p2[k];
        }
    }

    return ans;

}

int main()
{
    long long test,i,j,k;

    scanf("%lld",&test);

    calc();

    for(i=0;i<test;i++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        scanf("%lld%lld",&x,&y);

        printf("%lld\n",solve());
    }

    return 0;
}
