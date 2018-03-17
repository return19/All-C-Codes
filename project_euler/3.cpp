#include<bits/stdc++.h>
using namespace std;

long long s[1100000];
long long p[1100000],P=-1;

long long max2(long long x,long long y)
{
    if(x>=y)
        return x;
    return y;
}

void calc()
{
    long long i,j,k;

    s[0]=s[1]=1;

    for(i=2;i<=1000100;i++)
    {

        if(!s[i])
        {
            p[++P]=i;
            k=1;

            for(j=i;j<=1000100;j=i*k)
            {

                s[j]=1;
                k++;
            }
        }
    }
    //cout<<"completed"<<endl;
}

long long solve(long long n)
{
    long long i,j,k;
    long long sq;
    long long x;
    long long max1=-1;

    sq=sqrt(n);

    for(i=0;p[i]<=sq+1;i++)
    {
        x=p[i];

        if(n%x==0)
        {
            max1=max2(x,max1);

            while(n%x==0)
            {
                n=n/x;
            }

            if(n==0||n==1)
                break;
        }
    }

    max1=max2(max1,n);

    return max1;
}


int main()
{
    long long test,i,j,k;
    long long n;
    long long ans;

    calc();

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        ans=solve(n);

        printf("%lld\n",ans);
    }

    return 0;
}















