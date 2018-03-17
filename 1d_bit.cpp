#include<bits/stdc++.h>
using namespace std;

class bit
{

    int arr[101000];
    int n;
    int i,j,k;

public:

    bit(){}

    bit(int n)
    {
        for(i=0;i<=n+10;i++)
            arr[i]=0;

        (*this).n=n;
    }

    void setn(int n)
    {
        (*this).n=n;
    }

    void init()
    {
        for(i=0;i<=n+10;i++)
            arr[i]=0;
    }

    void increase(int idx,int val)
    {
        for(int i=idx;i<=n+1;)
        {
            arr[i] += val;

            i += (i)&(-i);
        }
    }

    int query(int idx)
    {
        int sum=0;

        while(idx>0)
        {
            sum += arr[idx];

            idx -= (idx)&(-idx);
        }

        return sum;
    }

    int query(int x,int y)
    {
        return query(y)-query(x-1);
    }
};

int main()
{
    int i,j,k;
    int n;
    int t;

    cin>>n;

    bit bt(n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);

        bt.increase(i,t);
    }

    for(i=1;i<=n;i++)
    {
        cout<<bt.query(i,i)<<" ";
    }

    cout<<endl<<bt.query(4,6)<<endl;




    return 0;
}
