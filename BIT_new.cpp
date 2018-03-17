#include<bits/stdc++.h>
using namespace std;

class bit
{
    long long arr[101010];
    int n;


    public:

    bit(){}

    bit(int n)
    {
        this->n=n;
        memset(arr,0,sizeof(long long)*(n+5));
    }

    long long query(int idx)
    {
        long long sum=0;

        while(idx>0)
        {
            sum+=arr[idx];
            idx=idx-(idx&(-idx));
        }
        return sum;
    }

    void update(int idx,int val)
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
    int x;
    int y;
}a;

a qry[11000000];

bool cmp(a p,a q)
{
    if(p.x!=q.x)
    {
        return (p.x<q.x);
    }

    return (p.y<q.y);
}

int main()
{
    int i,j;
    int n,m,k;
    int test;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&n,&m,&k);

        bit bt(m+1);

        for(j=0;j<k;j++)
        {
            scanf("%d%d",&qry[j].x,&qry[j].y);
        }

        sort(qry,qry+k,cmp);

        long long sum=0;

        for(j=0;j<k;j++)
        {
            sum=sum+bt.query(m+1)-bt.query(qry[j].y);

            bt.update(qry[j].y,1);
        }

        printf("Test case %d: %lld\n",i+1,sum);


    }

    return 0;
}







