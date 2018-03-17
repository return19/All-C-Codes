#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo_p;
map<long long,long long> memo_n;

long long abs1(long long x)
{
    if(x>=0)
    {
        return x;
    }

    return (-1)*x;
}

long long min1(long long x,long long y)
{
    if(x<=y)
        return x;
    return y;
}

int main()
{
    long long test,i,j,k;
    long long x,y;
    long long n,k1;
    long long ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        memo_p.clear();
        memo_n.clear();

        scanf("%lld%lld",&n,&k1);

        if(k1==0)
        {
            long long a=n*n;

            printf("%lld\n",a);
            continue;
        }

        if(k1==1)
        {
            long long x,y;

            scanf("%lld%lld",&x,&y);

            long long a=n*n;

            long long x1,x2,x3,x4;

            x1=min1(x,y);
            x2=min1(n-y+1,x);
            x3=min1(y,n-x+1);
            x4=min1(n-x+1,n-y+1);

            //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
            a=a-x1-x2-x3-x4+3;
            printf("%lld\n",a);
            continue;
        }


        long long sum=0;

        for(j=0;j<k1;j++)
        {
            scanf("%lld%lld",&x,&y);


            long long x1,x2,x3,x4;

            x1=min1(x,y);
            x2=min1(n-y+1,x);
            x3=min1(y,n-x+1);
            x4=min1(n-x+1,n-y+1);


            if(memo_p[x+y]!=1)
            {
                sum=sum+x2+x3;
            }

            if(memo_n[x-y]!=1)
            {
                sum=sum+x1+x4;
            }

            memo_p[x+y]=1;
            memo_n[x-y]=1;

           // memo[y-x]=1;
        }

        cout<<sum<<endl;


        ans=n*n-sum;

        printf("%lld\n",ans);

    }

    return 0;
}
