#include<bits/stdc++.h>
using namespace std;


class bit
{
    long long arr[1000010];
    long long n;


    public:

    bit(){}

    bit(long long n)
    {
        this->n=n;
        memset(arr,0,sizeof(long long)*(n+5));
    }

    void reset(long long n)
    {
        this->n=n;
        memset(arr,0,sizeof(long long)*(n+5));
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

    void r_update(long long l,long long r,long long val,bit &temp)
    {
        //arr[l]+=val;
        //arr[r+1] += -1*val;
        //temp[l]+=(1-l)*val;
        //temp[r+1]=r*val;
        update(l,val);
        update(r+1,((-1)*val));
        temp.update(l,((1-l)*val));
        temp.update(r+1,r*val);
    }

    long long r_query(long long l,bit &temp)
    {
        long long sum1=0,sum2=0;

        sum1=l*(query(l));
        //cout<<"here "<<sum1<<endl;
        sum2=temp.query(l);
        //cout<<"here2 "<<sum2<<endl;

        return (sum1+sum2);
    }

    void show()
    {
        for(int i=0;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

//long long arr[1010];

bit bt;
bit temp;

int main()
{
    long long test,i,j,k;
    long long c;
    long long type,p,q,v;
    long long n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        //memset(arr,0,sizeof(arr));

        scanf("%lld%lld",&n,&c);

        bt.reset(n+10);
        temp.reset(n+10);

        for(j=0;j<c;j++)
        {
            scanf("%lld",&type);

            if(type==0)
            {
                scanf("%lld%lld%lld",&p,&q,&v);

                bt.r_update(p,q,v,temp);

               // bt.show();
                //temp.show();
            }
            else
            {
                scanf("%lld%lld",&p,&q);
                long long ans=bt.r_query(q,temp)-bt.r_query(p-1,temp);

                //cout<<bt.r_query(q,temp)<<"  "<<bt.r_query(p-1,temp)<<endl;

                printf("%lld\n",ans);
            }
        }
    }



    return 0;
}











