#include<bits/stdc++.h>
using namespace std;

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

class bit
{
    long long arr[101010];
    long long n;


    public:

    bit(){}

    bit(long long n)
    {
        this->n=n;
    }

    long long query(long long idx)
    {
        long long sum=0;

        while(idx>0)
        {
            sum+=arr[idx];
            idx=idx-(idx&(-idx));
        }
        return sum;
    }

    void update(long long idx,long long val)
    {
        while(idx<=n)
        {
            arr[idx]+=val;
            idx=idx+(idx&(-idx));
        }
    }
};

typedef struct a1
{
    long long x;
    long long y;
}ar;

long long cmp(ar a,ar b)
{
    if(a.x!=b.x)
    {
        return (a.x<b.x);
    }

    return (a.y<b.y);
}

ar arr[100000010];

int main()
{
    long long n,m,k;
    long long i,j,x,y;
    long long test;
    long long sum;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        memset(arr,0,sizeof(arr));

        scanf("%lld%lld%lld",&n,&m,&k);

        bit bt(max2(n,m)+10);

        sum=0;

        for(j=1;j<=k;j++)
        {
            scanf("%lld%lld",&arr[j].y,&arr[j].x);
        }

        sort(arr+1,arr+k+1,cmp);

        for(j=1;j<=k;j++)
        {
            x=arr[j].x;
            y=arr[j].y;

            sum=sum+bt.query(n+5)-bt.query(y);
           // cout<<bt.query(n+1)<<" "<<bt.query(y)<<endl;

            bt.update(y,1);

        }

        printf("Test case %lld: %lld\n",i+1,sum);
    }

    return 0;
}




















