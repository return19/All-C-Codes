#include<bits/stdc++.h>
using namespace std;

long long MOD=1000000007;
long long n,k,n1;

class bit
{
    public: long long arr[50010];
    long long n;


    public:

    bit(){

       // memset(arr,0,sizeof(long long)*(n+5));
    }

    void setn(long long x)
    {
        n=x;
        memset(arr,0,sizeof(long long)*(n+5));

    }

    bit(long long n)
    {
        this->n=n;
        memset(arr,0,sizeof(long long)*(n+5));
    }

    long long query(long long idx)
    {
        long long sum=0;

        while(idx>0)
        {
            sum=(sum+arr[idx])%MOD;
            idx=idx-(idx&(-idx));
        }
        return sum;
    }

    void update(long long idx,long long val)
    {
        while(idx<=n+3)
        {
            arr[idx]=(arr[idx]+val)%MOD;
            idx=idx+(idx&(-idx));
        }
    }


};

bit bt[128];

 void show()
    {
        long long i,j;

        for(i=0;i<(1<<k);i++)
        {
            for(j=0;j<=n+25;j++)
            {
                cout<<bt[i].arr[j]<<" ";
            }

            cout<<endl;
        }
    }

int main()
{
    long long i,j;

    long long x,y;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<(1<<k);i++)
        bt[i].setn(50005);

    bt[0].update(1,1);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        x++;
        y--;

        for(j=(1<<k)-1;j>=0;j--)
        {
            long long d=bt[j].query(x-1);

            bt[j|(1<<y)].update(x,d);
        }
    }

   // show();

    printf("%lld\n",bt[(1<<k)-1].query(n+3));




    return 0;
}
















